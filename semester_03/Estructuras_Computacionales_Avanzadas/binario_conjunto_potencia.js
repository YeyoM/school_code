const array = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't']
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
  // Sacamos el numero de posibles combinaciones, para luego sacar el numero
  // en binario del numero posible de combinaciones y poder llenar la tabla
  // binaria correctamente y despues poder calcular el conjunto potencia
  let numPosiblesCombinaciones = numPosibleCombinaciones(length) - 1
  let maxLengthBinary = decimalBinario(numPosiblesCombinaciones).split('').length
  // Creamos un loop que cicle de 0 al numero de posibles combinaciones
  // que es el numero se subconjuntos dentro del conjunto potencia
  for (let i = 0; i <= numPosiblesCombinaciones; i++) {
    // Generamos el binario de i con todos los ceros posibles
    let binary = decimalBinario(i, maxLengthBinary).split('').reverse()
    let result = []
    // recorremos digito por digito el numero binario recien creado
    for (let j = 0; j < binary.length; j++) {
      // si el digito actual es 1 agregamos el elemento del array original
      // al nuevo array de resultados
      if (binary[j] === '1') {
        result.push(arr[j])
      }
    }
    // Una vez recorridos todos los digitos del numero binario de i
    // Podeos imprimir el binario y el conjunto potencia que le corresponda
    console.log(`${binary.reverse().join(' ')} -> {${result}}`)
  }
}

console.log(array.reverse().join(' '))
console.log('------------------------')
tablaBinaria(array.reverse(), length)
