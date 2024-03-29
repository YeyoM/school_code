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
    
    # Generar camino de salida a entrada
    x = m - 1
    y = n - 1
    caminos[x][y] = '1'
    movimiento_anterior = ''

    movimientos_posibles = obtener_posibles_movimientos(x, y, m, n, movimiento_anterior)
    probabilidades = obtener_probabilidades(probabildades_salida_entrada, movimientos_posibles)
    
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
      movimientos_posibles = obtener_posibles_movimientos(x, y, m, n, movimiento_anterior)
      probabilidades = obtener_probabilidades(probabildades_salida_entrada, movimientos_posibles)
  
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
  
  probabilidades_reales = []

  for i in movimientos_posibles:
    if i == 'up':
      probabilidades_reales.append(probabilidades[0])
    elif i == 'down':
      probabilidades_reales.append(probabilidades[1])
    elif i == 'left':
      probabilidades_reales.append(probabilidades[2])
    elif i == 'right':
      probabilidades_reales.append(probabilidades[3])

  # Normalizar probabilidades
  probabilidades_reales = [i / sum(probabilidades_reales) for i in probabilidades_reales]
  
  return probabilidades_reales

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


def juntar_laberintos(caminos, laberinto_aleatorio):
  for i in range(len(caminos)):
    for j in range(len(caminos)):
      if caminos[i][j] == '1':
        laberinto_aleatorio[i][j] = '1'
  return laberinto_aleatorio

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

  # Parte 1. Generar Caminos
  m = 40
  n = 40
  caminos = generar_caminos(m, n)
  imprimir_laberinto(caminos)

  # Parte 2. Generar laberinto
  m = 40
  n = 40
  densidad = 0.6
  laberinto_aleatorio = generar_laberinto(m, n, densidad)
  imprimir_laberinto(laberinto_aleatorio)

  # Parte 3. Juntar laberintos
  laberinto = juntar_laberintos(caminos, laberinto_aleatorio)
  imprimir_laberinto(laberinto)



if __name__ == "__main__":
  _main_()
