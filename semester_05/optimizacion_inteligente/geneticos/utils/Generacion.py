import numpy as np

# Importamos la funcion para calcular las horas de cada materia
from utils.CalcularHoras import CalcularHoras

# Aqui generamos los individuos, Agregando a Individuo el valor de cada modulo que generamos aleatoriamente
# @Modulo9 es un contador que nos ayuda a saber cuantos individuos se han generado
# @Choques es una funcion que nos ayuda a saber si el individuo tiene choques de horario
def Generacion(Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8, Modulo9, Poblacion):
    # RESTRICCIONES DE MATERIAS Y SEMESTRES
    # Aqui obtenemos el grado/grupo para los Modulos 1 y 2
    # Este numero es un entero entre 1 y 5 (representando 1er, 3er, 5to, 7mo y 9no semestre)
    # Esto se debe a que un alumno solo puede cursar materias de su semestre
    Grado = np.random.randint(0, 5)
    Materia = np.random.choice(Modulo1[Grado])

    # RESTRICCIONES DE HORARIOS
    # Aqui obtenemos el horario de inicio y fin de la materia para los modulos 4 y 6
    # El horario de inicio debe ser menor al horario de fin 
    Hora_Inicio = np.random.randint(0, 7)
    Hora_Fin = np.random.randint(Hora_Inicio, 7)

    # RESTRICCIONES DE HORAS CUMPLIDAS (max 5hrs por materia)
    Dia_Inicio = np.random.randint(0, 3)
    Dia_Fin = np.random.randint(0, 2)
    # Calculamos las horas que dura la materia
    Horas = CalcularHoras(Modulo4[Hora_Inicio], Modulo3[Dia_Inicio], Modulo6[Hora_Fin], Modulo5[Dia_Fin])

    while Horas > 5:
        Hora_Inicio = np.random.randint(0, 7)
        Hora_Fin = np.random.randint(Hora_Inicio, 7)
        Dia_Inicio = np.random.randint(0, 3)
        Dia_Fin = np.random.randint(0, 2)
        Horas = CalcularHoras(Modulo4[Hora_Inicio], Modulo3[Dia_Inicio], Modulo6[Hora_Fin], Modulo5[Dia_Fin])

    # RESTRICCIONES DE TIPOS DE AULAS Y AULAS
    # Aqui obtenemos el tipo de aula y el aula para los modulos 7 y 8
    # El aula tiene que corresponder con el tipo que es
    # Por ejemplo, si el tipo de aula es "Aula", el aula debe ser "54 A", "54 C", "54 F", "54 G" o "54 H"
    Tipo_Aula = np.random.randint(0, 3)

    Individuo = [
        np.random.choice(Modulo1[Grado]), 
        Modulo2[Grado], 
        Modulo3[Dia_Inicio],
        Modulo4[Hora_Inicio],
        Modulo5[Dia_Fin], 
        Modulo6[Hora_Fin],
        Modulo7[Tipo_Aula],
        np.random.choice(Modulo8[Tipo_Aula]), 
        Modulo9
    ]

    Poblacion.append(Individuo)
    Modulo9 = Modulo9 + 1
    Individuo.append(0)
    return Individuo
