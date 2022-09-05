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

// Para saber si existe bucles en la matriz, encontraremos un 1
// en la diagonal principal de la matriz
let bucles = Array(grafo.length).fill(0)
let nodos = grafo.length
let cuenta = 0

function recorrerGrafo() {
  for (let i = 0; i < nodos; i++) {
    for (let j = 0; j < nodos; j++) {
      if (grafo[i][j] === 1 && i === j) {
        bucles[i] = 1
        cuenta++
      }
    }
  }
}

recorrerGrafo()

if (cuenta > 0) {
  console.log("El grafo tiene bucles")
  console.log("Los nodos con bucles son: " + bucles)
} else {
  console.log("El grafo no tiene bucles")
}

