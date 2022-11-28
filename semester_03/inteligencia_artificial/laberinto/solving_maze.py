import random
import numpy as np


def imprimir_laberinto(laberinto):

  #Cambiar 2 por 🟩
  #Cambiar 0 por 🟦
  #Cambiar 1 por 🟨

  # crear copia del laberinto
  laberinto_copia = laberinto.copy()

  for i in range(len(laberinto_copia)):
    for j in range(len(laberinto_copia[0])):
      if laberinto_copia[i][j] == '0':
        laberinto_copia[i][j] = '🟦'
      elif laberinto_copia[i][j] == '1':
        laberinto_copia[i][j] = '🟨'
      elif laberinto_copia[i][j] == '2':
        laberinto_copia[i][j] = '🟩'

  print('\n'.join(''.join(fila) for fila in laberinto_copia))
  print()


# Generar una cuadricula 
def generar_cuadricula(n, m, laberinto):

  laberinto = np.full((m, n), '0')
  
  for i in range(m):
    if i % 2 == 0:
      laberinto[i] = np.full(n, '0')
    else:
      for j in range(n):
        if j % 2 == 0:
          laberinto[i][j] = '0'
        else:
          laberinto[i][j] = '1'

  return laberinto

def obtener_vecinos(laberinto, i, j, visitados):

  vecinos = []

  if i > 1 and [i-2, j] not in visitados:
    vecinos.append([i-2, j])
  
  if i < len(laberinto)-2 and [i+2, j] not in visitados:
    vecinos.append([i+2, j])

  if j > 1 and [i, j-2] not in visitados:
    vecinos.append([i, j-2])

  if j < len(laberinto[0])-2 and [i, j+2] not in visitados:
    vecinos.append([i, j+2])

  return vecinos

def obtener_vecinos_solucion(laberinto, i, j, visitados):

  vecinos = []

  if i > 1 and [i-2, j] not in visitados:
    vecinos.append([i-2, j])
  
  if i < len(laberinto)-2 and [i+2, j] not in visitados:
    vecinos.append([i+2, j])

  if j > 1 and [i, j-2] not in visitados:
    vecinos.append([i, j-2])

  if j < len(laberinto[0])-2 and [i, j+2] not in visitados:
    vecinos.append([i, j+2])

  vecinos_solucion = []

  # Comprobar si entre el actual y el vecino hay un 1
  for vecino in vecinos:
    if vecino[0] == i and vecino[1] == j + 2 :
      if laberinto[i][j+1] == '1':
        vecinos_solucion.append(vecino)
    elif vecino[0] == i and vecino[1] == j - 2:
      if laberinto[i][j-1] == '1':
        vecinos_solucion.append(vecino)
    elif vecino[0] == i + 2 and vecino[1] == j:
      if laberinto[i+1][j] == '1':
        vecinos_solucion.append(vecino)
    elif vecino[0] == i - 2 and vecino[1] == j:
      if laberinto[i-1][j] == '1':
        vecinos_solucion.append(vecino)

  return vecinos_solucion


# Con DFS solucion de un laberinto
def solucionar_laberinto_dfs(laberinto, inicio, fin):
  
    visitados = []
    stack = []
    vecinos = []
  
    actual = inicio
  
    while True:
      visitados.append(actual)
  
      # Obtener vecinos
      vecinos = obtener_vecinos_solucion(laberinto, actual[0], actual[1], visitados)

      if vecinos:
        # Escoger un vecino al azar
        vecino = random.choice(vecinos)

        # Marcar el vecino como visitado
        visitados.append(vecino)
  
        # Insertar el vecino en la pila
        stack.append(actual)
  
        # Actualizar el actual
        actual = vecino
  
      else:
        if stack:
          actual = stack.pop()
        else:
          break
  
      if actual == fin:
        break

    # Marcar el camino
    for i in range(len(visitados)):
      if i < len(visitados)-1:
        actual = visitados[i]
        siguiente = visitados[i+1]
        # Obtener la coordenada entre visitados[i] y visitados[i+1]
        if actual[0] == siguiente[0]:
          if actual[1] < siguiente[1]:
            laberinto[actual[0]][actual[1]+1] = '2'
          elif actual[1] > siguiente[1]:
            laberinto[actual[0]][actual[1]-1] = '2'
        elif actual[1] == siguiente[1]:
          if actual[0] < siguiente[0]:
            laberinto[actual[0]+1][actual[1]] = '2'
          elif actual[0] > siguiente[0]:
            laberinto[actual[0]-1][actual[1]] = '2'

      laberinto[visitados[i][0]][visitados[i][1]] = '2'

def solucionar_laberinto_bfs(laberinto, inicio, fin):
  
    visitados = []
    queue = []
    vecinos = []
  
    actual = inicio
  
    while True:
      visitados.append(actual)
  
      # Obtener vecinos
      vecinos = obtener_vecinos_solucion(laberinto, actual[0], actual[1], visitados)

      if vecinos:
        # Escoger un vecino al azar
        vecino = random.choice(vecinos)

        # Marcar el vecino como visitado
        visitados.append(vecino)
  
        # Insertar el vecino en la cola
        queue.append(actual)
  
        # Actualizar el actual
        actual = vecino
  
      else:
        if queue:
          actual = queue.pop(0)
        else:
          break
  
      if actual == fin:
        break

    # Marcar el camino
    for i in range(len(visitados)):
      if i < len(visitados)-1:
        actual = visitados[i]
        siguiente = visitados[i+1]
        # Obtener la coordenada entre visitados[i] y visitados[i+1]
        if actual[0] == siguiente[0]:
          if actual[1] < siguiente[1]:
            laberinto[actual[0]][actual[1]+1] = '2'
          elif actual[1] > siguiente[1]:
            laberinto[actual[0]][actual[1]-1] = '2'
        elif actual[1] == siguiente[1]:
          if actual[0] < siguiente[0]:
            laberinto[actual[0]+1][actual[1]] = '2'
          elif actual[0] > siguiente[0]:
            laberinto[actual[0]-1][actual[1]] = '2'

      laberinto[visitados[i][0]][visitados[i][1]] = '2'

def _main_():

  m = 41
  n = 41
  
  laberinto = []
  visitados = []
  stack = []
  vecinos = []

  # Generar una cuadricula
  laberinto = generar_cuadricula(n, m, laberinto)
  imprimir_laberinto(laberinto)

  actual = [1, 1]

  # Con DFS generar un laberinto
  while True:

    visitados.append(actual)

    # Obtener vecinos
    vecinos = obtener_vecinos(laberinto, actual[0], actual[1], visitados)

    if vecinos:
      # Escoger un vecino al azar
      vecino = random.choice(vecinos)

      # Marcar el vecino como visitado
      visitados.append(vecino)

      # Insertar el vecino en la pila
      stack.append(actual)

      # Eliminar la pared entre el vecino y el actual
      laberinto[int((actual[0]+vecino[0])/2)][int((actual[1]+vecino[1])/2)] = '1'

      # Actualizar el actual
      actual = vecino

    else:
      if stack:
        actual = stack.pop()
      else:
        break
  
  # Imprimir el laberinto
  imprimir_laberinto(laberinto)

  laberinto_para_dfs = laberinto.copy()
  laberinto_para_bfs = laberinto.copy()
 
  # Solucionar el laberinto
  solucionar_laberinto_dfs(laberinto_para_dfs, [1, 1], [m-2, n-2])
  imprimir_laberinto(laberinto_para_dfs)

  solucionar_laberinto_bfs(laberinto_para_bfs, [1, 1], [m-2, n-2])
  imprimir_laberinto(laberinto_para_bfs)

if __name__ == "__main__":
  _main_()