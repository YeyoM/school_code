const matrizA = [
  [8, 4, -1, 7, -2], 
  [-2, -4, 9, 6, 7],
  [7, -6, 2, 5, -2]
]
const matrizB = [
  [3, 3, 7],
  [-3, 7, 6],
  [5, -9, 7],
  [-3, -6, -9],
  [-3, -8, -2]
]

let m = matrizA.length
let p = matrizA[0].length
let n = matrizB[0].length
let q = matrizB.length

if (p !== q) {
  console.log('No se pueden multiplicar')
} else {
  let matrizC = []
  for (let i = 0; i < m; i++) {
    matrizC[i] = []
    for (let j = 0; j < n; j++) {
      matrizC[i][j] = 0
      for (let k = 0; k < p; k++) {
        matrizC[i][j] += matrizA[i][k] * matrizB[k][j]
      }
    }
  }
  console.log(matrizC)
}