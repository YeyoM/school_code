let num = 13

const decimalBinario = (num) => {
  let arr = []
  if (num === 0) {
    return 0
  }
  while (num !== 0) {
    arr.push(num % 2)
    num = Math.trunc(num / 2)
  }
  return arr.reverse().join('')
}

const tablaBinaria = (num) => {
  for (let i = 0; i <= num; i++) {
    console.log(`${i} = ${decimalBinario(i)}`)
  }
}

const result = decimalBinario(num)
console.log(`El binario de ${num} es ${result}`)
tablaBinaria(num)
