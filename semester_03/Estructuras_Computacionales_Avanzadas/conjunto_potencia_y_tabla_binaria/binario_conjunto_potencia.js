const array = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u']
const length = array.length

// tiene complejidad O(logn + n + n) -> O(n)
const decimalBinario = (num, length) => {
  let arr = []
  if (num === 0) {
    arr.push(0)
  }

  // este bucle tiene complejidad de O(logn)
  // ya que cada vez se acerca más a la condición
  // de paro
  
  while (num !== 0) {
    arr.push(num % 2)
    num = Math.trunc(num / 2)
  }

  // Esta parte tiene como complejidad de O(n), teniendo 
  // como n a la cantidad de ceros que siempre será menor
  // o igual a la cantidad de elementos del conjunto inicial
  if (arr.length < length) {
    let ceros = length - arr.length
    for (let i = 0; i < ceros; i++) {
      arr.push(0)
    }
  }

  // arr.prototype.reverse tiene complejidad O(n)
  return arr.reverse().join('')
}

const numPosibleCombinaciones = (length) => {
  return Math.pow(2, length)
}


const tablaBinaria = (arr, length) => {

  // Sacamos el numero de posibles combinaciones, para luego sacar el numero
  // en binario del numero posible de combinaciones y poder llenar la tabla
  // binaria correctamente y despues poder calcular el conjunto potencia

  // Complejidad de O(1)
  let numPosiblesCombinaciones = numPosibleCombinaciones(length) - 1

  // Complejidad de O(N), con N = numero de posibles combinaciones
  let maxLengthBinary = decimalBinario(numPosiblesCombinaciones).split('').length

  // Creamos un loop que cicle de 0 al numero de posibles combinaciones
  // que es el numero se subconjuntos dentro del conjunto potencia

  // Este for tiene complejidad de O((n + 1) * n) -> lo que resulta en O(n2)
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
    console.log(`${binary.join(' ')} -> {${result}}`)
  }
}

// Complejidad de O(n2)
tablaBinaria(array, length)
