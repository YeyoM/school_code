// En este ejemplo el grafo tiene 11 vertices, por lo que la matriz es de 11x11
// Al ser un grafo no dirigido, la matriz es simetrica
let grafo = [
  [0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0],
  [0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0],
  [0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0],
  [0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0],
  [1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
  [0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0],
  [0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0],
  [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1],
  [1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0],
  [1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0],
  [0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1]
]

// Creamos un array de visitados, para saber si ya hemos visitado un nodo
// Inicialmente todos los nodos estan sin visitar, representados con un 0
let visitados = Array(grafo.length).fill(0)
let nodos = grafo.length
let cuenta = 0

/**
 * Recibe un nodo como argumento, y comprueba si el nodo ha sido visitado. Si no ha sido visitado,
 * lo marca como visitado, y comprueba si el nodo tiene conexiones con otros nodos. Si tiene conexiones,
 * llama a la funcion de nuevo, pasando el nodo conectado como argumento
 * @param iteradorVisitados - el nodo que se esta visitando
 */
function recorrerGrafo(iteradorVisitados) {
  cuenta++
  visitados[iteradorVisitados] = 1

  for (let i = 0; i < nodos; i++) {
    // Si el nodo tiene conexion con otro nodo, y el nodo al que esta conectado no ha sido visitado
    if (grafo[iteradorVisitados][i] === 1 && visitados[i] === 0) {
      recorrerGrafo(i)
    }
  }
}

// Recorremos el grafo desde el nodo 0
recorrerGrafo(0)

// Si la cuenta de nodos visitados es igual al numero de nodos, el grafo es conexo
if (cuenta === nodos) console.log("El grafo es conexo")
else console.log("El grafo no es conexo")


