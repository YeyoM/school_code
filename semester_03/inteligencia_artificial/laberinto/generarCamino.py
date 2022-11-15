"""
  Procedimiento a seguir para el algoritmo

  1. Generar 2 caminos (soluciones) aleatorios

    - Nuestros movimientos posibles son: 
      arriba, abajo, izquierda, derecha

    - Los caminos se verán reflejados en una 
      matriz que representará el laberinto

    a. El primer camino será de entrada a salida

      - Para este caso los posibles movimientos 
        tienen un porcetaje de ocurrir diferente
        uno del otro

        arriba: 15%
        abajo: 35%
        derecha: 35%
        izquierda: 15%

    b. El segundo camino será de salida a entrada

    - Para este caso los posibles movimientos 
        tienen un porcetaje de ocurrir diferente
        uno del otro

        arriba: 35%
        abajo: 15%
        derecha: 15%
        izquierda: 35%

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