const arr = ['a', 'b', 'c', 'd']
const n = arr.length

const factorial = (n) => {
  if (n === 1) {
    return n
  } else {
    return n * factorial(n - 1)
  }
}

const combinacion = (n, r) => {
  return (factorial(n) / (factorial(n - r) * factorial(r)))
}

const mostrarCombinaciones = (arr, n) => {
  for (let i = 0; i < n; i++) {
    for (let j = (i + 1); j < n; j++) {
      console.log(arr[i], arr[j])
    }
  }
  
}

mostrarCombinaciones(arr, n)
console.log(combinacion(n, 2))
