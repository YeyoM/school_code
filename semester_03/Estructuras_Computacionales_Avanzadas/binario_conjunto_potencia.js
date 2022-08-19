const array = ['a', 'b', 'c', 'd', 'e', 'f', 'g']
const length = array.length

const decimalBinario = (num, length) => {
  let arr = []
  if (num === 0) {
    arr.push(0)
  }
  while (num !== 0) {
    arr.push(num % 2)
    num = Math.trunc(num / 2)
  }

  if (arr.length < length) {
    let ceros = length - arr.length
    for (let i = 0; i < ceros; i++) {
      arr.push(0)
    }
  }

  return arr.reverse().join('')
}

const tablaBinaria = (arr, length) => {
  // calcular el numero binario del lenght del array
  // ese es el segundo argumento de la funcion decimalBinario
  for (let i = 0; i <= length; i++) {
    console.log(`${i} = ${decimalBinario(i, 3)}`) // -> 3 es el numero de digitos del numero binario mas grande
  }
}

tablaBinaria(array, length)