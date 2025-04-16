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

# Límites para decorador de cruce\ nBOUNDS_LOW = [0, INCLINACION_MIN, ORIENTACION_MIN, PANELES_MIN]
BOUNDS_LOW = [0, INCLINACION_MIN, ORIENTACION_MIN, PANELES_MIN]
BOUNDS_HIGH = [1, INCLINACION_MAX, ORIENTACION_MAX, PANELES_MAX]

# Decorador genérico para recortar hijos tras el crossover
def check_bounds(min_vals, max_vals):
    def decorator(func):
        def wrapper(ind1, ind2, *args, **kwargs):
            off1, off2 = func(ind1, ind2, *args, **kwargs)
            for ind in (off1, off2):
                # Tipo de panel: entero 0 o 1
                ind[0] = max(min_vals[0], min(max_vals[0], int(round(ind[0]))))
                # Inclinación
                ind[1] = max(min_vals[1], min(max_vals[1], ind[1]))
                # Orientación
                ind[2] = max(min_vals[2], min(max_vals[2], ind[2]))
                # Número de paneles: entero en [PANELES_MIN, PANELES_MAX]
                ind[3] = max(min_vals[3], min(max_vals[3], int(round(ind[3]))))
            return off1, off2
        return wrapper
    return decorator

# --------------------------
# Modelo de energía generada
# --------------------------

def calcular_energia(tipo, inclinacion, orientacion, num_paneles):
    """
    Calcula la energía generada por la configuración de paneles solares.
    """
    tipo = max(0, min(1, int(round(tipo))))
    panel = TIPOS_PANELES[tipo]

    factor_inclinacion = max(0.5, 1 - 0.005 * abs(inclinacion - 30))
    desviacion_sur = min(abs(orientacion - 180), 360 - abs(orientacion - 180))
    factor_orientacion = max(0.5, 1 - 0.001 * desviacion_sur)
    captacion_relativa = panel["captacion_relativa"] * factor_inclinacion * factor_orientacion

    energia_panel = IRRADIANCIA * panel["eficiencia"] * AREA_PANEL * captacion_relativa
    return energia_panel * num_paneles

# --------------------------
# Función de evaluación
# --------------------------

def evaluar(individuo):
    tipo = int(round(individuo[0]))
    inclinacion = individuo[1]
    orientacion = individuo[2]
    num_paneles = max(1, int(round(individuo[3])))

    tipo_idx = max(0, min(1, tipo))
    costo = num_paneles * TIPOS_PANELES[tipo_idx]["costo"]
    energia = calcular_energia(tipo, inclinacion, orientacion, num_paneles)

    if costo > PRESUPUESTO_MAX:
        return 0.0, costo
    else:
        return energia, costo

# --------------------------
# Configurar DEAP y NSGA-II
# --------------------------

# Eliminar creadores anteriores si existen
if 'FitnessMulti' in creator.__dict__:
    del creator.FitnessMulti
if 'Individual' in creator.__dict__:
    del creator.Individual

creator.create("FitnessMulti", base.Fitness, weights=(1.0, -1.0))
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

# Registramos cxBlend y lo decoramos para recortar límites
toolbox.register("mate", tools.cxBlend, alpha=0.5)
toolbox.decorate("mate", check_bounds(BOUNDS_LOW, BOUNDS_HIGH))

# Mutación personalizada
def custom_mutate(individual, indpb, sigma, low, up):
    size = len(individual)
    for i in range(size):
        if random.random() <= indpb:
            if i == 0:
                individual[i] = 1 - individual[i] if random.random() < 0.5 else individual[i]
            elif i == 3:
                delta = random.randint(-3, 3)
                new_val = int(round(individual[i])) + delta
                individual[i] = max(low[i], min(up[i], new_val))
            else:
                new_val = individual[i] + random.gauss(0, sigma * (up[i] - low[i]))
                individual[i] = max(low[i], min(up[i], new_val))
    return individual,

toolbox.register("mutate", custom_mutate,
                 indpb=0.2,
                 sigma=0.1,
                 low=[0, INCLINACION_MIN, ORIENTACION_MIN, PANELES_MIN],
                 up=[1, INCLINACION_MAX, ORIENTACION_MAX, PANELES_MAX])

toolbox.register("select", tools.selNSGA2)

# --------------------------
# Ejecutar algoritmo
# --------------------------

def main():
    random.seed(42)
    np.random.seed(42)

    POP_SIZE = 100
    NGEN = 100
    MU = 100
    LAMBDA = 100
    CXPB = 0.7
    MUTPB = 0.3

    pop = toolbox.population(n=POP_SIZE)
    fitnesses = list(map(toolbox.evaluate, pop))
    for ind, fit in zip(pop, fitnesses):
        ind.fitness.values = fit

    stats = tools.Statistics(lambda ind: ind.fitness.values)
    stats.register("avg", np.mean, axis=0)
    stats.register("min", np.min, axis=0)
    stats.register("max", np.max, axis=0)

    pop, logbook = algorithms.eaMuPlusLambda(pop, toolbox, mu=MU, lambda_=LAMBDA,
                                             cxpb=CXPB, mutpb=MUTPB, ngen=NGEN,
                                             stats=stats, verbose=True)
    return pop, logbook

if __name__ == "__main__":
    final_pop, log = main()

    soluciones_validas = []
    for ind in final_pop:
        energia = ind.fitness.values[0]
        costo = ind.fitness.values[1]
        tipo_idx = max(0, min(1, int(round(ind[0]))))
        if costo <= PRESUPUESTO_MAX and energia > 0.5:
            soluciones_validas.append({
                "tipo_panel": TIPOS_PANELES[tipo_idx]["nombre"],
                "inclinacion": round(ind[1], 2),
                "orientacion": round(ind[2], 2),
                "num_paneles": int(round(ind[3])),
                "energia_total_kWh_dia": round(energia, 2),
                "costo_total_usd": round(costo, 2),
                "ratio_costo_energia": round(costo / energia, 2) if energia > 0 else float('inf')
            })

    soluciones_validas.sort(key=lambda x: x["ratio_costo_energia"])

    if soluciones_validas:
        with open("soluciones_paneles.csv", "w", newline="") as f:
            writer = csv.DictWriter(f, fieldnames=soluciones_validas[0].keys())
            writer.writeheader()
            writer.writerows(soluciones_validas)
        print(f"\nSe guardaron {len(soluciones_validas)} soluciones válidas en 'soluciones_paneles.csv'.")

        energia_vals = [s["energia_total_kWh_dia"] for s in soluciones_validas]
        costo_vals = [s["costo_total_usd"] for s in soluciones_validas]
        tipos = [1 if s["tipo_panel"] == "Monocristalino" else 0 for s in soluciones_validas]

        plt.figure(figsize=(10, 6))
        plt.scatter(costo_vals, energia_vals, c=tipos, alpha=0.8, s=80, edgecolors='black')
        plt.grid(True, linestyle='--', alpha=0.7)
        plt.xlabel("Costo Total (USD)")
        plt.ylabel("Energía Total (kWh/día)")
        plt.title("Frente de Pareto: Optimización de Sistema de Paneles Solares")

        legend_labels = ['Policristalino', 'Monocristalino']
        legend = plt.legend(handles=plt.gca().collections[0].legend_elements()[0], labels=legend_labels,
                            title="Tipo de Panel", loc="upper left")

        if len(soluciones_validas) >= 3:
            best = soluciones_validas[0]
            plt.annotate(
                f"Mejor solución:\n{best['num_paneles']} paneles {best['tipo_panel']}\n"
                f"Energía: {best['energia_total_kWh_dia']} kWh/día\n"
                f"Costo: ${best['costo_total_usd']}",
                xy=(best['costo_total_usd'], best['energia_total_kWh_dia']),
                xytext=(30, -50), textcoords='offset points',
                arrowprops=dict(arrowstyle='->', connectionstyle='arc3,rad=.2')
            )

        plt.tight_layout()
        plt.savefig("frente_pareto_paneles.png", dpi=300)
        plt.show()

        print("\nMejores 5 soluciones por relación costo/energía:")
        for i, sol in enumerate(soluciones_validas[:5], 1):
            print(f"{i}. {sol['num_paneles']} paneles {sol['tipo_panel']}, "
                  f"inclinación: {sol['inclinacion']}°, orientación: {sol['orientacion']}°, "
                  f"Energía: {sol['energia_total_kWh_dia']} kWh/día, "
                  f"Costo: ${sol['costo_total_usd']}, "
                  f"USD/kWh: {sol['ratio_costo_energia']}")
    else:
        print("No se encontraron soluciones válidas que cumplan con el presupuesto.")
        
