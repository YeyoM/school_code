const arr = ['a', 'b', 'c', 'd']
const n = arr.length

const factorial = (n) => {
  if (n === 1) {
    return n
  } else {
    return n * factorial(n - 1)
  }
}

const permutacion = (n, r) => {
  return (factorial(n) / factorial(n - r))
}

const seleccionarUno = (arr, seleccionados, iterador) => {
  let seleccionado
  for (let i = 0; i < arr.length; i++) {
    if (arr[i] !== seleccionados[iterador]) {
      seleccionado = arr[i]
      break
    }
  }
  return seleccionado
}

const mostrarPermutaciones = (arr) => {
  var result = [];
    return result;
}

console.log(permutacion(n, 3))
mostrarPermutaciones(arr)
