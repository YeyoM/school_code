"""
Universidad Autonoma de Aguascalientes
Centro de Ciencias Basicas
Departamento de Ciencias de la Computacion
Carrera: Ingenieria en Computacion Inteligente
Materia: Machine Learning
Profesor: Dr. Francisco Javier Luna Rosas
Alumno: Diego Emilio Moreno Sanchez
"""

"""
Neurona de McCulloch-Pitts y algoritmo del perceptrón simple

Determinar si se le aprueba o no, una terjeta de crédito a un cliente
considerando la edad y el ahorro que tiene en su cuenta
"""

import matplotlib.pyplot as plt
import numpy as np

# Datos de entrada (edad y ahorro)
personas = np.array(
    [
        [0.3, 0.4],
        [0.4, 0.3],
        [0.3, 0.2],
        [0.4, 0.1],
        [0.5, 0.4],
        [0.4, 0.8],
        [0.6, 0.8],
        [0.5, 0.6],
        [0.7, 0.6],
        [0.8, 0.5],
    ]
)

# Claase 1: Aprobado
# Clase 0: No aprobado
clases = np.array([0, 0, 0, 0, 0, 1, 1, 1, 1, 1])


# Función de activación
# w1 * x1 + w2 * x2 + ... + wn * xn
def activacion(pesos, x, b):
    z = pesos * x
    if z.sum() + b > 0:
        return 1
    else:
        return 0


pesos = np.random.uniform(-1, 1, 2)
b = np.random.uniform(-1, 1)

print("Pesos iniciales:", pesos)
print("Sesgo inicial:", b)
print("Salida:", activacion(pesos, [0.8, 0.5], b))

# Entrenamiento
pesos = np.random.uniform(-1, 1, 2)
b = np.random.uniform(-1, 1)
tasa_aprendizaje = 0.01
epocas = 100

for epoca in range(epocas):
    errores = 0
    for i in range(len(personas)):
        prediccion = activacion(pesos, personas[i], b)
        error = clases[i] - prediccion
        errores += error**2
        pesos[0] += tasa_aprendizaje * error * personas[i][0]
        pesos[1] += tasa_aprendizaje * error * personas[i][1]
        b += tasa_aprendizaje * error
    print(f"Epoca: {epoca}, Error: {errores}")

# Evaluación
print("Pesos finales:", pesos)
print("Sesgo final:", b)
print("Salida:", activacion(pesos, [0.8, 0.5], b))
