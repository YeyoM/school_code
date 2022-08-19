const array = ['a', 'b', 'c', 'd', 'e']
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

const numPosibleCombinaciones = (length) => {
  return Math.pow(2, length)
}

const tablaBinaria = (arr, length) => {
  let numPosiblesCombinaciones = numPosibleCombinaciones(length) - 1
  let maxLengthBinary = decimalBinario(numPosiblesCombinaciones).split('').length
  for (let i = 0; i <= numPosiblesCombinaciones; i++) {
    let binary = decimalBinario(i, maxLengthBinary).split('').reverse()
    let result = []
    for (let j = 0; j < binary.length; j++) {
      if (binary[j] === '1') {
        result.push(arr[j])
      }
    }
    console.log(`${binary.reverse().join('')} = ${result}`)
  }
}

console.log(array)
tablaBinaria(array, length)