let num = 11

const decimalBinario = (num) => {
  let arr = []
  while (num !== 0) {
    arr.push(num % 2)
    num = Math.trunc(num / 2)
  }
  return arr.reverse().join('')
}

const result = decimalBinario(num)
console.log(`El binario de ${num} es ${result}`)
