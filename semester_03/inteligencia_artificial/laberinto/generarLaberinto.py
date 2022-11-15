# Crear un laberinto aleatorio en Python3 usando el algoritmo de
# recorrido en profundidad. El propósito de este programa es mostrar las
# características del lenguaje.
# 
# Autor: Mario Abarca
# Fecha: 2017/09/07

from itertools import product  # Producto cartesiano
from random import randint, shuffle  # Números pseudoaleatorios


def laberinto(m, n):

    """
    > It returns the coordinates of the neighbors of a cell in a 2D grid
    
    :param i: the row index of the current cell
    :param j: the column number
    :param m: the number of rows
    :param n: the number of columns
    """
    def vecinos(i, j):   
      if 0 < i: 
        yield i - 1, j
      
      if i < m - 1: 
        yield i + 1, j

      if 0 < j: 
        yield i, j - 1

      if j < n - 1: 
        yield i, j + 1

    """
    > The function `visitar` takes as input a pair of integers `i` and `j` and adds the pair to the
    set `X`. Then it shuffles the list of neighbors of `(i, j)` and for each neighbor `(h, k)` of
    `(i, j)` it checks if `(h, k)` is in `X`. If it is, it continues to the next neighbor.
    Otherwise, it sets the value of `A[i + h + 1][j + k + 1]` to `' '` and calls `visitar` with `h`
    and `k` as input
      
    :param i: the row of the current cell
    :param j: The number of columns
    """
    def visitar(i, j):    

      X.add((i, j))  

      N = list(vecinos(i, j)); shuffle(N) 

      for h, k in N:                  
        if (h, k) in X: 
          continue    

        A[i + h + 1][j + k + 1] = ' '  
        visitar(h, k)  

    # Tablero lleno de paredes
    A = [['█']*(2*n + 1) for i in range(2*m + 1)]
    # print('\n'.join(''.join(fila) for fila in A))

    # Ponemos celdas blancas, una si y una no
    for i, j in product(range(1, 2*m + 1, 2), range(1, 2*n + 1, 2)):
      A[i][j] = ' '   
    print('\n'.join(''.join(fila) for fila in A))               

    # Conjunto de celdas visitadas
    X = set()                           

    visitar(randint(1, 1), randint(9, 9))  

    return('\n'.join(''.join(fila) for fila in A))  # Unir símbolos en un str


print(laberinto(10, 10))