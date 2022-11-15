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

  3. Buscar el camino más corto entre la entrada y la salida

    - Usar diferentes algoritmos para comparar
    
    a. BFS
    b. DFS
    c. A*
    d. Dijkstra

"""

import random
import numpy as np

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

    movimientos_posibles = obtener_posibles_movimientos(x, y, m, n, movimiento_anterior)
    probabilidades = obtener_probabilidades(probabildades_entrada_salida, movimientos_posibles)

    print(movimientos_posibles)
    print(probabilidades)

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
      movimientos_posibles = obtener_posibles_movimientos(x, y, m, n, movimiento_anterior)
      probabilidades = obtener_probabilidades(probabildades_entrada_salida, movimientos_posibles)
    
    print(caminos)


    # Generar camino de salida a entrada
    x = m - 1
    y = n - 1
    caminos[x][y] = '1'
  
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
  probabilidades_entrada_salida = [i / sum(probabilidades_entrada_salida) for i in probabilidades_entrada_salida]
  
  return probabilidades_entrada_salida

# PARTE 2. GENERAR LABERINTO
def generar_laberinto(m, n, densidad):

  # Paredes -> 0
  # Espacios -> 1

  # Generar matriz de laberinto
  laberinto = np.full((m, n), '1')

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
      laberinto[i][j] = '0'

  return laberinto

def imprimir_laberinto(laberinto):
  # Cambiar 0 por █
  # Cambiar 1 por ' '
  for i in range(len(laberinto)):
    for j in range(len(laberinto[0])):
      if laberinto[i][j] == '0':
        laberinto[i][j] = '█'
      else:
        laberinto[i][j] = ' '
  print('\n'.join(''.join(fila) for fila in laberinto))



def _main_():

  # Parte 1. Generar Caminos
  m = 18
  n = 18
  caminos = generar_caminos(m, n)

  # Parte 2. Generar laberinto
  m = 40
  n = 40
  densidad = 0.4
  laberinto_aleatorio = generar_laberinto(m, n, densidad)
  imprimir_laberinto(laberinto_aleatorio)

if __name__ == "__main__":
  _main_()