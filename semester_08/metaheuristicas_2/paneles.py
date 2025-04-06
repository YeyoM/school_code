import random
import numpy as np
import csv
from deap import base, creator, tools, algorithms
import matplotlib.pyplot as plt

# --------------------------
# Parámetros del problema
# --------------------------

IRRADIANCIA = 5  # kWh/m²/día
AREA_PANEL = 1.6  # m²
PRESUPUESTO_MAX = 5000  # USD

# Paneles
TIPOS_PANELES = {
    0: {"nombre": "Policristalino", "eficiencia": 0.16, "captacion_relativa": 0.85, "costo": 180},
    1: {"nombre": "Monocristalino", "eficiencia": 0.20, "captacion_relativa": 1.0, "costo": 250}
}

# Restricciones
INCLINACION_MIN, INCLINACION_MAX = 0, 45
ORIENTACION_MIN, ORIENTACION_MAX = 0, 360
PANELES_MIN, PANELES_MAX = 1, 50

# --------------------------
# Modelo de energía generada - Versión mejorada
# --------------------------
def calcular_energia(tipo, inclinacion, orientacion, num_paneles):
    """
    Calcula la energía generada por la configuración de paneles solares usando un modelo continuo.
    
    Args:
        tipo (int): Tipo de panel (0=Policristalino, 1=Monocristalino)
        inclinacion (float): Ángulo de inclinación de los paneles en grados
        orientacion (float): Orientación de los paneles en grados (0-360, donde 180=Sur)
        num_paneles (int): Número de paneles en la instalación
        
    Returns:
        float: Energía total generada en kWh/día
    """
    # Asegurar que tipo sea un entero válido (0 o 1)
    tipo = max(0, min(1, int(round(tipo))))
    panel = TIPOS_PANELES[tipo]
    
    # Calcular el factor de captación relativa de forma continua
    # Máxima captación en sur (180°) con inclinación óptima (30°)
    factor_inclinacion = max(0.5, 1 - 0.005 * abs(inclinacion - 30))
    
    # Factor de orientación (máximo en 180° = sur)
    desviacion_sur = min(abs(orientacion - 180), 360 - abs(orientacion - 180))
    factor_orientacion = max(0.5, 1 - 0.001 * desviacion_sur)
    
    # Combinación de factores
    captacion_relativa = panel["captacion_relativa"] * factor_inclinacion * factor_orientacion
    
    # Cálculo de energía
    energia_panel = IRRADIANCIA * panel["eficiencia"] * AREA_PANEL * captacion_relativa
    return energia_panel * num_paneles

# --------------------------
# Función de evaluación
# --------------------------
def evaluar(individuo):
    """
    Evalúa un individuo calculando la energía generada y el costo total.
    Penaliza soluciones que exceden el presupuesto máximo.
    
    Args:
        individuo (list): Lista con [tipo_panel, inclinacion, orientacion, num_paneles]
        
    Returns:
        tuple: (energia, costo) para maximizar energía y minimizar costo
    """
    tipo = int(round(individuo[0]))  # Asegurar tipo como entero 0 o 1
    inclinacion = individuo[1]
    orientacion = individuo[2]
    num_paneles = max(1, int(round(individuo[3])))  # Mínimo 1 panel
    
    # Asegurar que tipo sea 0 o 1 para indexar correctamente
    tipo_idx = max(0, min(1, tipo))
    costo = num_paneles * TIPOS_PANELES[tipo_idx]["costo"]
    
    energia = calcular_energia(tipo, inclinacion, orientacion, num_paneles)
    
    if costo > PRESUPUESTO_MAX:
        # Penalizar soluciones que exceden el presupuesto
        return 0.0, costo  # Energía cero si excede presupuesto, mantener costo real
    else:
        return energia, costo  # Maximizar energía, minimizar costo

# --------------------------
# Configurar DEAP y NSGA-II
# --------------------------
# Eliminar creadores anteriores si existen
if 'FitnessMulti' in creator.__dict__:
    del creator.FitnessMulti
if 'Individual' in creator.__dict__:
    del creator.Individual

# IMPORTANTE: Cambiamos los pesos a positivo para energía y negativo para costo
creator.create("FitnessMulti", base.Fitness, weights=(1.0, -1.0))  # Maximizar energía, minimizar costo
creator.create("Individual", list, fitness=creator.FitnessMulti)

toolbox = base.Toolbox()
toolbox.register("tipo", random.randint, 0, 1)
toolbox.register("inclinacion", random.uniform, INCLINACION_MIN, INCLINACION_MAX)
toolbox.register("orientacion", random.uniform, ORIENTACION_MIN, ORIENTACION_MAX)
toolbox.register("num_paneles", random.randint, PANELES_MIN, PANELES_MAX)

toolbox.register("individual", tools.initCycle, creator.Individual,
                 (toolbox.tipo, toolbox.inclinacion, toolbox.orientacion, toolbox.num_paneles), n=1)
toolbox.register("population", tools.initRepeat, list, toolbox.individual)

toolbox.register("evaluate", evaluar)
toolbox.register("mate", tools.cxBlend, alpha=0.5)

# Versión simplificada y robusta de mutación para evitar cualquier problema con números complejos
def custom_mutate(individual, indpb, sigma, low, up):
    """
    Implementación simplificada de mutación que usa distribución normal
    y evita completamente los números complejos.
    """
    size = len(individual)
    for i in range(size):
        if random.random() <= indpb:
            # Para el tipo de panel, simplemente alternar entre 0 y 1
            if i == 0:
                individual[i] = 1 - individual[i] if random.random() < 0.5 else individual[i]
                continue
                
            # Para el número de paneles, aplicar cambio discreto
            if i == 3:
                # Añadir o quitar paneles de forma aleatoria
                delta = random.randint(-3, 3)
                new_val = int(round(individual[i])) + delta
                individual[i] = max(low[i], min(up[i], new_val))
                continue
                
            # Para inclinación y orientación, usar distribución normal simple
            # Añadir ruido gaussiano
            new_val = individual[i] + random.gauss(0, sigma * (up[i] - low[i]))
            # Asegurar que está dentro de los límites
            individual[i] = max(low[i], min(up[i], new_val))
    
    return individual,

# Registramos nuestra función personalizada de mutación simplificada
toolbox.register("mutate", custom_mutate, 
                 indpb=0.2,  # Probabilidad de mutar cada gen
                 sigma=0.1,  # Desviación estándar relativa al rango
                 low=[0, INCLINACION_MIN, ORIENTACION_MIN, PANELES_MIN],
                 up=[1, INCLINACION_MAX, ORIENTACION_MAX, PANELES_MAX])

toolbox.register("select", tools.selNSGA2)

# --------------------------
# Ejecutar algoritmo
# --------------------------
def main():
    """
    Función principal que ejecuta el algoritmo NSGA-II
    
    Returns:
        tuple: (población final, registro estadístico)
    """
    random.seed(42)
    np.random.seed(42)
    
    # Parámetros del algoritmo
    POP_SIZE = 100
    NGEN = 100
    MU = 100
    LAMBDA = 100
    CXPB = 0.7  # Probabilidad de cruce
    MUTPB = 0.3  # Probabilidad de mutación
    
    # Inicializar población
    pop = toolbox.population(n=POP_SIZE)
    
    # Evaluar la población inicial
    fitnesses = list(map(toolbox.evaluate, pop))
    for ind, fit in zip(pop, fitnesses):
        ind.fitness.values = fit
    
    # Estadísticas
    stats = tools.Statistics(lambda ind: ind.fitness.values)
    stats.register("avg", np.mean, axis=0)
    stats.register("min", np.min, axis=0)
    stats.register("max", np.max, axis=0)
    
    # Ejecución del algoritmo
    pop, logbook = algorithms.eaMuPlusLambda(pop, toolbox, mu=MU, lambda_=LAMBDA,
                                             cxpb=CXPB, mutpb=MUTPB, ngen=NGEN,
                                             stats=stats, verbose=True)
    
    return pop, logbook

if __name__ == "__main__":
    final_pop, log = main()
    
    # --------------------------
    # Filtrar soluciones válidas y guardar CSV
    # --------------------------
    soluciones_validas = []
    for ind in final_pop:
        # Calcular valores reales para mostrar
        energia = ind.fitness.values[0]  # Ya no es negativo
        costo = ind.fitness.values[1]
        tipo_idx = max(0, min(1, int(round(ind[0]))))
        
        # Filtrar soluciones válidas con energía significativa y dentro del presupuesto
        if costo <= PRESUPUESTO_MAX and energia > 0.5:
            soluciones_validas.append({
                "tipo_panel": TIPOS_PANELES[tipo_idx]["nombre"],
                "inclinacion": round(ind[1], 2),
                "orientacion": round(ind[2], 2),
                "num_paneles": int(round(ind[3])),
                "energia_total_kWh_dia": round(energia, 2),
                "costo_total_usd": round(costo, 2),
                "ratio_costo_energia": round(costo / energia, 2) if energia > 0 else float('inf')  # Métrica adicional: USD por kWh/día
            })
    
    # Ordenar soluciones por mejor relación costo/energía
    soluciones_validas.sort(key=lambda x: x["ratio_costo_energia"])
    
    # Guardar resultados
    if soluciones_validas:
        with open("soluciones_paneles.csv", "w", newline="") as f:
            writer = csv.DictWriter(f, fieldnames=soluciones_validas[0].keys())
            writer.writeheader()
            writer.writerows(soluciones_validas)
        
        print(f"\nSe guardaron {len(soluciones_validas)} soluciones válidas en 'soluciones_paneles.csv'.")
        
        # --------------------------
        # Graficar Frente de Pareto
        # --------------------------
        energia = [s["energia_total_kWh_dia"] for s in soluciones_validas]
        costo = [s["costo_total_usd"] for s in soluciones_validas]
        tipos = [1 if s["tipo_panel"] == "Monocristalino" else 0 for s in soluciones_validas]
        
        # Crear figura
        plt.figure(figsize=(10, 6))
        
        # Gráfico principal: Frente de Pareto
        scatter = plt.scatter(costo, energia, c=tipos, cmap='coolwarm', 
                              alpha=0.8, s=80, edgecolors='black')
        
        # Líneas guía
        plt.grid(True, linestyle='--', alpha=0.7)
        
        # Etiquetas y título
        plt.xlabel("Costo Total (USD)", fontsize=12)
        plt.ylabel("Energía Total (kWh/día)", fontsize=12)
        plt.title("Frente de Pareto: Optimización de Sistema de Paneles Solares", fontsize=14)
        
        # Leyenda
        legend_labels = ['Policristalino', 'Monocristalino']
        legend = plt.legend(handles=scatter.legend_elements()[0], labels=legend_labels, 
                           title="Tipo de Panel", loc="upper left")
        
        # Mostrar métricas de las 3 mejores soluciones
        if len(soluciones_validas) >= 3:
            plt.annotate(
                f"Mejor solución:\n{soluciones_validas[0]['num_paneles']} paneles {soluciones_validas[0]['tipo_panel']}\n"
                f"Energía: {soluciones_validas[0]['energia_total_kWh_dia']} kWh/día\n"
                f"Costo: ${soluciones_validas[0]['costo_total_usd']}",
                xy=(soluciones_validas[0]['costo_total_usd'], soluciones_validas[0]['energia_total_kWh_dia']),
                xytext=(30, -50), textcoords='offset points',
                arrowprops=dict(arrowstyle='->', connectionstyle='arc3,rad=.2')
            )
        
        # Mostrar gráfico
        plt.tight_layout()
        plt.savefig("frente_pareto_paneles.png", dpi=300)
        plt.show()
        
        # Mostrar las 5 mejores soluciones
        print("\nMejores 5 soluciones por relación costo/energía:")
        for i, sol in enumerate(soluciones_validas[:5], 1):
            print(f"{i}. {sol['num_paneles']} paneles {sol['tipo_panel']}, "
                  f"inclinación: {sol['inclinacion']}°, orientación: {sol['orientacion']}°, "
                  f"Energía: {sol['energia_total_kWh_dia']} kWh/día, "
                  f"Costo: ${sol['costo_total_usd']}, "
                  f"USD/kWh: {sol['ratio_costo_energia']}")
    else:
        print("No se encontraron soluciones válidas que cumplan con el presupuesto.")