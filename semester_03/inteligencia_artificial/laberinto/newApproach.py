import random
import numpy as np

def imprimir_laberinto(laberinto):
  # Cambiar 0 por ⬛
  # Cambiar 1 por ⬜

  # crear copia del laberinto
  laberinto_copia = laberinto.copy()

  for i in range(len(laberinto_copia)):
    for j in range(len(laberinto_copia[0])):
      if laberinto_copia[i][j] == '0':
        laberinto_copia[i][j] = '⬛'
      else:
        laberinto_copia[i][j] = '⬜'

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

  # Imprimir el laberinto\
  imprimir_laberinto(laberinto)



if __name__ == "__main__":
  _main_()