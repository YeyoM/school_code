
#---------------- Importamos las librerias necesarias -------------------
import numpy as np

#-----------------Agregamos los valores de los pesos y thetas----------------

# Agregamos los valores de los pesos
pesos1 = np.array([0.2, -0.3])
pesos2 = np.array([0.4, 0.1])
pesos3 = np.array([-0.5, 0.2])
pesos4 = -0.3
pesos5 = -0.2

# Agregamos el valor de los thetas
theta4 = -0.4
theta5 = 0.2
theta6 = 0.1

# Agregamos el valor de las entradas
x1 = 1
x2 = 0
x3 = 1

Learning = 0.5

# -----------Funciones para la salida-------------------------------
def Salida_4():
    global pesos1, pesos2, pesos3, theta4
    z = np.dot(pesos1[0], x1) + np.dot(pesos2[0], x2) + np.dot(pesos3[0], x3) + theta4
    z = 1 / (1 + np.exp(-z))
    return z

def Salida_5():
    global pesos1, pesos2, pesos3, theta5
    z = np.dot(pesos1[1], x1) + np.dot(pesos2[1], x2) + np.dot(pesos3[1], x3) + theta5
    z = 1 / (1 + np.exp(-z))
    return z

def Salida_6():
    global pesos4, pesos5, theta6
    salida_4 = Salida_4()
    salida_5 = Salida_5()
    z = pesos4 * salida_4 + pesos5 * salida_5 + theta6
    z = 1 / (1 + np.exp(-z))
    return z

# ----Calcular errores------------------------------------------------
def Error_6():
    salida_6 = Salida_6()
    error = salida_6 * (1 - salida_6) * (1 - salida_6)
    return error

def Error_4():
    salida_4 = Salida_4()
    error = salida_4 * (1 - salida_4) * Error_6()
    return error

def Error_5():
    salida_5 = Salida_5()
    error = salida_5 * (1 - salida_5) * Error_6()
    return error

# ----Calcular el cambio de pesos-------------------------------------

def Cambio_pesos():
    global pesos1, pesos2, pesos3, pesos4, pesos5, x1, x2, x3, Learning
    pesos1[0] = pesos1[0] + Learning * Error_4() * x1
    pesos1[1] = pesos1[1] + Learning * Error_5() * x1
    pesos2[0] = pesos2[0] + Learning * Error_4() * x2
    pesos2[1] = pesos2[1] + Learning * Error_5() * x2
    pesos3[0] = pesos3[0] + Learning * Error_4() * x3
    pesos3[1] = pesos3[1] + Learning * Error_5() * x3
    pesos4 = pesos4 + Learning * Error_6() * Salida_4()
    pesos5 = pesos5 + Learning * Error_6() * Salida_5()

# --------------Calcular el cambio de theta----------------------------
def Cambio_theta():
    global theta4, theta5, theta6, Learning
    theta4 = theta4 + Learning * Error_4()
    theta5 = theta5 + Learning * Error_5()
    theta6 = theta6 + Learning * Error_6()

# -----------------Imprimir resultados--------------------------------

def Algoritmo():
    for i in range(10000):
        Cambio_pesos()
        Cambio_theta()
    print('------------------------------')
    print('RESULTADOS')
    print("Salida de la neurona 6", Salida_6())
    print("Error de la neurona 6", Error_6())
    print('------------------------------')
    print('PESOS')
    print('Pesos 1:', pesos1)
    print('Pesos 2:', pesos2)
    print('Pesos 3:', pesos3)
    print('Pesos 4:', pesos4)
    print('Pesos 5:', pesos5)

# -----------------Comprobamos los resultados-------------------------
Algoritmo()


