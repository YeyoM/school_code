"""
  Procedimiento a seguir para el algoritmo

  1. Generar 2 caminos (soluciones) aleatorios

    - Nuestros movimientos posibles son: 
      up, down, left, right

    - Los caminos se verán reflejados en una 
      matriz que representará el laberinto

    a. El primer camino será de entrada a salida

      - Para este caso los posibles movimientos 
        tienen un porcetaje de ocurrir diferente
        uno del otro

        up: 15%
        down: 35%
        right: 35%
        left: 15%

    b. El segundo camino será de salida a entrada

    - Para este caso los posibles movimientos 
        tienen un porcetaje de ocurrir diferente
        uno del otro

        up: 35%
        down: 15%
        right: 15%
        left: 35%

    NOTA: vamos a ir guardando siempre el último 
          movimiento que se hizo para no elegir
          su movimiento contrario

  2. Generar de manera aleatoria el laberinto

    - Para esto vamos a ir generando paredes
      aleatorias en el laberinto, siempre tomando
      en cuenta el porcentaje de obstaculos, este
      numero puede variar entre un 40 y un 70%

  3. Juntar los laberintos generados en un solo
     tomando como prioridad el de los caminos

  4. Buscar el camino más corto entre la entrada y la salida

    - Usar diferentes algoritmos para comparar
    
    a. BFS
    b. DFS
    c. A*
    d. Dijkstra

"""

import random
import numpy as np
from collections import deque
from heapq import heappop, heappush
import ipdb

# generate random integer values
from random import seed
from random import randint

# PARTE 1. GENERAR CAMINOS


def generar_caminos(m, n):

    # Generar matriz de caminos
    caminos = np.full((m, n), '0')

    movimiento_anterior = ''
    movimientos_posibles = ['up', 'down', 'left', 'right']
    probabildades_entrada_salida = [0.15, 0.35, 0.15, 0.35]
    probabildades_salida_entrada = [0.35, 0.15, 0.35, 0.15]

    # Generar camino de entrada a salida
    x = 0
    y = 0
    caminos[x][y] = '1'

    movimientos_posibles = obtener_posibles_movimientos(
        x, y, m, n, movimiento_anterior)
    probabilidades = obtener_probabilidades(
        probabildades_entrada_salida, movimientos_posibles)

    #print(movimientos_posibles)
    #print(probabilidades)

    while (x != m - 1 or y != n - 1):
        movimiento = np.random.choice(movimientos_posibles, p=probabilidades)
        if movimiento == 'up':
            x -= 1
        elif movimiento == 'down':
            x += 1
        elif movimiento == 'left':
            y -= 1
        elif movimiento == 'right':
            y += 1
        caminos[x][y] = '1'
        movimiento_anterior = movimiento
        movimientos_posibles = obtener_posibles_movimientos(
            x, y, m, n, movimiento_anterior)
        probabilidades = obtener_probabilidades(
            probabildades_entrada_salida, movimientos_posibles)

    # Generar camino de salida a entrada
    x = m - 1
    y = n - 1
    caminos[x][y] = '1'
    movimiento_anterior = ''

    movimientos_posibles = obtener_posibles_movimientos(
        x, y, m, n, movimiento_anterior)
    probabilidades = obtener_probabilidades(
        probabildades_salida_entrada, movimientos_posibles)

    #print(movimientos_posibles)
    #print(probabilidades)

    while (x != 0 or y != 0):
        movimiento = np.random.choice(movimientos_posibles, p=probabilidades)
        if movimiento == 'up':
            x -= 1
        elif movimiento == 'down':
            x += 1
        elif movimiento == 'left':
            y -= 1
        elif movimiento == 'right':
            y += 1
        caminos[x][y] = '1'
        movimiento_anterior = movimiento
        movimientos_posibles = obtener_posibles_movimientos(
            x, y, m, n, movimiento_anterior)
        probabilidades = obtener_probabilidades(
            probabildades_salida_entrada, movimientos_posibles)

    return caminos


def obtener_posibles_movimientos(x, y, m, n, movimiento_anterior):

    movimientos_posibles = ['up', 'down', 'left', 'right']

    if movimiento_anterior == 'up':
        movimientos_posibles.remove('down')
    elif movimiento_anterior == 'down':
        movimientos_posibles.remove('up')
    elif movimiento_anterior == 'left':
        movimientos_posibles.remove('right')
    elif movimiento_anterior == 'right':
        movimientos_posibles.remove('left')

    if (x <= 0):
        movimientos_posibles.remove('up')
    if (x >= m - 1):
        movimientos_posibles.remove('down')
    if (y <= 0):
        movimientos_posibles.remove('left')
    if (y >= n - 1):
        movimientos_posibles.remove('right')

    return movimientos_posibles


def obtener_probabilidades(probabilidades, movimientos_posibles):

    probabilidades_entrada_salida = []

    for i in movimientos_posibles:
        if i == 'up':
            probabilidades_entrada_salida.append(probabilidades[0])
        elif i == 'down':
            probabilidades_entrada_salida.append(probabilidades[1])
        elif i == 'left':
            probabilidades_entrada_salida.append(probabilidades[2])
        elif i == 'right':
            probabilidades_entrada_salida.append(probabilidades[3])

    # Normalizar probabilidades
    probabilidades_entrada_salida = [
        i / sum(probabilidades_entrada_salida) for i in probabilidades_entrada_salida]

    return probabilidades_entrada_salida

# PARTE 2. GENERAR LABERINTO


def generar_laberinto(m, n, valoresAleatorios):

    # Paredes -> 0
    # Espacios -> 1

    # Generar matriz de laberinto
    laberinto = np.full((m, n), '1')

    # Generar obstaculos por linea
    for i in range(m):
        densidad = randint(55, 67)
        valoresAleatorios.append(densidad)
        obstaculos = int(n * densidad/100)
        # Generar obstaculos aleatorios
        obstaculos = random.sample(range(n), obstaculos)
        obstaculos = obstaculos[:-2]
        obstaculos.append(0)
        obstaculos.append(n - 1)
        # Poner obstaculos en la fila
        for j in obstaculos:
            laberinto[i][j] = '0'

    return laberinto

def reducirCaminosFila(fila, densidadActual, densidadObjetivo, n, m):

    # print('Reduciendo caminos de la fila', fila)
    #print('Densidad actual:', densidadActual)
    #print('Densidad objetivo:', densidadObjetivo)

    cantidadObtasculosObjetivo = int(n * densidadObjetivo/100)
    cantidadObstaculosActual = int(n * densidadActual/100)

    #print('Cantidad de obstaculos objetivo:', cantidadObtasculosObjetivo)
    #print('Cantidad de obstaculos actual:', cantidadObstaculosActual)

    while (cantidadObstaculosActual < cantidadObtasculosObjetivo):
        # seleccionar entre 1 y cantidadObstaculosObjetivos - cantidadObstaculosActual para mutar
        cantidadObstaculosMutar = randint(1, cantidadObtasculosObjetivo - cantidadObstaculosActual)
        # print('Cantidad de obstaculos a mutar:', cantidadObstaculosMutar)
        # seleccionar obstaculos a mutar
        obstaculosMutar = random.sample(range(n), cantidadObstaculosMutar)
        # mutar obstaculos
        for i in obstaculosMutar:
            if (fila[i] == '0'):
                fila[i] = '1'
            elif (fila[i] == '1'):
                fila[i] = '0'

        cantidadObstaculosActual = list(fila).count('0')
        # print('Cantidad de obstaculos actual:', cantidadObstaculosActual)
        # print('Cantidad de obstaculos objetivo:', cantidadObtasculosObjetivo)

    return fila

def comprobarLaberinto(laberinto, m, n, valoresAleatorios):

    for i in range(m):
        # contar los ceros de cada fila y comprobar con los valores aleatorios (obstaculos)
        densidadActual = list(laberinto[i]).count('0') * 100 / n
        if (densidadActual < valoresAleatorios[i]):
            # reducir caminos
            #print("Reducir Caminos")
            reducirCaminosFila(laberinto[i], densidadActual, valoresAleatorios[i], n, m)
        elif (densidadActual > valoresAleatorios[i]):
            print("Aumentar Caminos")
        else:
            print("Correcto")

    return laberinto


def juntar_laberintos(caminos, laberinto_aleatorio):
    for i in range(len(caminos)):
        for j in range(len(caminos)):
            if caminos[i][j] == '1':
                laberinto_aleatorio[i][j] = '1'
    return laberinto_aleatorio

def escarbar_laberinto(laberinto, m, n):

    # Escarbar laberinto
    # Escarbar hasta encontrar un camino o un obstaculo (uno y uno)

    movimiento_anterior = ''
    movimientos_posibles = ['up', 'down', 'left', 'right']
    probabildades = [0.15, 0.35, 0.15, 0.35]

    # Generar camino de entrada a salida
    x = 0
    y = 0
    laberinto[x][y] = '1'

    movimientos_posibles = obtener_posibles_movimientos(x, y, m, n, movimiento_anterior)
    probabilidades = obtener_probabilidades(probabildades, movimientos_posibles)

    while (x != m - 1 or y != n - 1):
        movimiento = np.random.choice(movimientos_posibles, p=probabilidades)
        if movimiento == 'up':
            # siguiente_camino = buscar_siguiente_camino(x, y, m, n, movimiento, laberinto)
            # print('Siguiente camino:', siguiente_camino)
            # # crear camino desde las coordenadas actuales hasta el siguiente camino
            # for i in range(x, siguiente_camino[0][0]):
            #     laberinto[i][y] = '1'
            # x = siguiente_camino[0][0]
            # y = siguiente_camino[0][1]
            # print("[", x, ",", y, "] -> [", siguiente_camino[0][0], ",", siguiente_camino[0][1], "]")
            x -= 1

        elif movimiento == 'down':
            #siguiente_camino = buscar_siguiente_camino(x, y, m, n, movimiento, laberinto)
            # crear camino desde las coordenadas actuales hasta el siguiente camino
            #print("[", x, ",", y, "] -> [", siguiente_camino[0], ",", siguiente_camino[1], "]")
            x += 1

        elif movimiento == 'left':
            siguiente_camino = buscar_siguiente_camino(x, y, m, n, movimiento, laberinto)
            #print('Siguiente camino:', siguiente_camino)
            # crear camino desde las coordenadas actuales hasta el siguiente camino
            if (siguiente_camino[0][0] == x and siguiente_camino[0][1] == y): 
                y -= 1
            else:
                print("[", x, ",", y, "] -> [", siguiente_camino[0][0], ",", siguiente_camino[0][1], "]")
                for i in range(y, siguiente_camino[0][1], -1):
                    laberinto[x][i] = '1'
                x = siguiente_camino[0][0]
                y = siguiente_camino[0][1]

        elif movimiento == 'right':
            siguiente_camino = buscar_siguiente_camino(x, y, m, n, movimiento, laberinto)
            # crear camino desde las coordenadas actuales hasta el siguiente camino
            if (siguiente_camino[0][0] == x and siguiente_camino[0][1] == y):
                y += 1
            else:
                # print("[", x, ",", y, "] -> [", siguiente_camino[0][0], ",", siguiente_camino[0][1], "]")
                for i in range(y, siguiente_camino[0][1]):
                    # print("[", x, ",", i, "]")
                    laberinto[x][i] = '1'
                x = siguiente_camino[0][0]
                y = siguiente_camino[0][1]

        laberinto[x][y] = '1'
        movimiento_anterior = movimiento
        movimientos_posibles = obtener_posibles_movimientos(x, y, m, n, movimiento_anterior)
        probabilidades = obtener_probabilidades(probabildades, movimientos_posibles)

    return laberinto

def buscar_siguiente_camino(x, y, m, n, movimiento_anterior, laberinto):
    
    coordenadas = []

    if movimiento_anterior == 'left':
        for i in range(y, 0, -1):
            if laberinto[x][i] == '1' and i != y:
                coordenadas.append([x, i])
                return coordenadas
        coordenadas.append([x, y - 1])

    elif movimiento_anterior == 'right':
        for i in range(y, n):
            if laberinto[x][i] == '1' and laberinto[x][i - 1] == '0':
                coordenadas.append([x, i])
                return coordenadas
        coordenadas.append([x, y + 1])

    return coordenadas

def imprimir_laberinto(laberinto):
    # Cambiar 0 por █
    # Cambiar 1 por ' '

    # crear copia del laberinto
    laberinto_copia = laberinto.copy()

    for i in range(len(laberinto_copia)):
        for j in range(len(laberinto_copia[0])):
            if laberinto_copia[i][j] == '0':
                laberinto_copia[i][j] = '█'
            else:
                laberinto_copia[i][j] = ' '
    print('\n'.join(''.join(fila) for fila in laberinto_copia))
    print()

def _main_():
    
    seed(1)

    valoresAleatorios = []

    # Parte 1. Generar Caminos
    m = 40
    n = 40
    caminos = generar_caminos(m, n)
    imprimir_laberinto(caminos)

    # Parte 2. Generar laberinto
    m = 40
    n = 40
    laberinto_aleatorio = generar_laberinto(m, n, valoresAleatorios)
    imprimir_laberinto(laberinto_aleatorio)

    # Parte 3. Juntar laberintos
    laberinto = juntar_laberintos(caminos, laberinto_aleatorio)
    imprimir_laberinto(laberinto)

    # Parte 4. Revisar cada fila y verificar que compla con el porcentaje entre 33 y 45% de caminos
    print("Valores aleatorios: ", valoresAleatorios)
    comprobarLaberinto(laberinto, m, n, valoresAleatorios)
    imprimir_laberinto(laberinto)

    # Parte 5. Escarbar laberinto
    escarbar_laberinto(laberinto, m, n)
    imprimir_laberinto(laberinto)

if __name__ == "__main__":
    _main_()
