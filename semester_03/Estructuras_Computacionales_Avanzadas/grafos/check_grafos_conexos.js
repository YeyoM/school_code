// Representar un grafo con una matriz 
// let grafoVacio = Array(6).fill(Array(6))

// En este ejemplo el grafo tiene 6 vertices, por lo que la matriz es de 6x6
// Al ser un grafo no dirigido, la matriz es simetrica
let grafo = [
  [0, 1, 0, 1, 1, 0],
  [1, 0, 1, 0, 0, 0],
  [0, 1, 0, 0, 1, 1],
  [1, 0, 0, 0, 1, 0],
  [1, 0, 1, 1, 0, 1],
  [0, 0, 1, 0, 1, 0]
]

// Creamos un array de visitados, para saber si ya hemos visitado un nodo
// Inicialmente todos los nodos estan sin visitar, representado con un 0
let visitados = Array(6).fill(0)
let nodos = 6
let cuenta = 0

// Creamos una funcion para recorrer el grafo (Busqueda en profundidad)
function recorrerGrafo(iteradorVisitados) {
  let iteradorGrafo = 0
  cuenta++
  visitados[iteradorVisitados] = 1

  for (let i = 0; i < nodos; i++) {
    if (grafo[iteradorVisitados][i] === 1 && visitados[i] === 0) {
      recorrerGrafo(i)
    }
  }
}

// Recorremos el grafo
recorrerGrafo(0)

// Si la cuenta de nodos visitados es igual al numero de nodos, el grafo es conexo
if (cuenta === nodos) {
  console.log("El grafo es conexo")
}
else {
  console.log("El grafo no es conexo")
}

