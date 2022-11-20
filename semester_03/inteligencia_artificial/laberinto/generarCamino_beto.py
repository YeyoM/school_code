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

# PARTE 1. GENERAR CAMINOS


def generar_caminos(m, n):

    # Generar matriz de caminos
    caminos = np.full((m, n), '1')

    movimiento_anterior = ''
    movimientos_posibles = ['up', 'down', 'left', 'right']
    probabildades_entrada_salida = [0.15, 0.35, 0.15, 0.35]
    probabildades_salida_entrada = [0.35, 0.15, 0.35, 0.15]

    # Generar camino de entrada a salida
    x = 0
    y = 0
    caminos[x][y] = '0'

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
        caminos[x][y] = '0'
        movimiento_anterior = movimiento
        movimientos_posibles = obtener_posibles_movimientos(
            x, y, m, n, movimiento_anterior)
        probabilidades = obtener_probabilidades(
            probabildades_entrada_salida, movimientos_posibles)

    # Generar camino de salida a entrada
    x = m - 1
    y = n - 1
    caminos[x][y] = '0'
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
        caminos[x][y] = '0'
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


def generar_laberinto(m, n, densidad):

    # Paredes -> 0
    # Espacios -> 1

    # Generar matriz de laberinto
    laberinto = np.full((m, n), '0')

    # Generar obstaculos por linea
    for i in range(m):
        # Generar 40% de obstaculos de la fila
        obstaculos = int(n * densidad)
        # Generar obstaculos aleatorios
        obstaculos = random.sample(range(n), obstaculos)
        obstaculos = obstaculos[:-2]
        obstaculos.append(0)
        obstaculos.append(n - 1)
        # Poner obstaculos en la fila
        for j in obstaculos:
            laberinto[i][j] = '1'

    return laberinto


def juntar_laberintos(caminos, laberinto_aleatorio):
    for i in range(len(caminos)):
        for j in range(len(caminos)):
            if caminos[i][j] == '0':
                laberinto_aleatorio[i][j] = '0'
    return laberinto_aleatorio


def imprimir_laberinto(laberinto):
    # Cambiar 0 por █
    # Cambiar 1 por ' '

    # crear copia del laberinto
    laberinto_copia = laberinto.copy()

    for i in range(len(laberinto_copia)):
        for j in range(len(laberinto_copia[0])):
            if laberinto_copia[i][j] == '1':
                laberinto_copia[i][j] = '█'
            else:
                laberinto_copia[i][j] = ' '
    print('\n'.join(''.join(fila) for fila in laberinto_copia))
    print()

# PARTE 3. GENERAR GRAFO
def maze2graph(maze):  # Obtenemos el grafo a partir del laberinto
    height = len(maze)
    width = len(maze)
    # Creating a dictionary with the coordinates of the maze as keys and an empty list as values.
    graph = {(i, j): [] for j in range(width) for i in range(height) if maze[i][j]}
    for row, col in graph:
        if row < height - 1 and  maze[row + 1][col]:
            graph[(row, col)].append(("S", (row + 1, col)))
            graph[(row + 1, col)].append(("N", (row, col)))
        if col < width - 1 and  maze[row][col + 1]:
            graph[(row, col)].append(("E", (row, col + 1)))
            graph[(row, col + 1)].append(("W", (row, col)))
    return graph

def _main_():

    # Parte 1. Generar Caminos
    m = 40
    n = 40
    caminos = generar_caminos(m, n)
    imprimir_laberinto(caminos)

    # Parte 2. Generar laberinto
    m = 40
    n = 40
    densidad = 0.7
    laberinto_aleatorio = generar_laberinto(m, n, densidad)
    imprimir_laberinto(laberinto_aleatorio)

    # Parte 3. Juntar laberintos
    laberinto = juntar_laberintos(caminos, laberinto_aleatorio)
    imprimir_laberinto(laberinto)

    # Parte 4. Generar solucion
    # Solucion BFS
    #print("Solucion BFS")
    #graphOfMaze = maze2graph(laberinto)
    #print(graphOfMaze)


if __name__ == "__main__":
    _main_()
