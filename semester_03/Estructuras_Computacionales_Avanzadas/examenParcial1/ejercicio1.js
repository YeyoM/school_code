/**
 * Supongamos que tenemos cuatro monedas con los siguientes valores: 
 * 1 peso, 2 pesos, 5 pesos y 10 pesos. 
 * ¿De qué maneras distintas podemos combinarlas y 
 * qué valor monetario obtenemos en cada caso?
 * 
 * Algoritmo para resolver el ejercicio:
 * Conjunto Potencia a partir de una tabla binaria
 * 1. Calculamos el numero de posibles combinaciones
 * 2. Calculamos el numero maximo de digitos que tendra el numero binario
 *    Para esto calculamos el numero binario del numero de posibles combinaciones
 *    y contamos la cantidad de digitos que tiene, en este caso 16 combinaciones
 *    nos da un numero binario de 4 digitos
 * 3. Creamos un loop que cicle de 0 al numero de posibles combinaciones
 *    que es el numero se subconjuntos dentro del conjunto potencia
 * 4. Generamos el binario de i con todos los ceros a la izquierda posibles
 * 5. Recorremos digito por digito el numero binario recien creado y en caso de
 *    encontrar un 1, agregamos el elemento del conjunto original en la posicion
 *    del digito y lo agregamos al subconjunto, junto con esto vamos calculando
 *    la suma de los elementos del subconjunt
 * 6. Imprimimos el subconjunto y la suma de sus elementos
 */

const monedas = [1, 2, 5, 10]
const length = monedas.length
let suma = 0

// Funcion que convierte un decimal a binario como se vio en clase
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

  // calculamos el numero de posibles combinaciones
  let numPosiblesCombinaciones = numPosibleCombinaciones(length) - 1

  // Calculamos el numero de digitos que tendrá cada elemento, calculando
  // el numero de digitos que tendrá el numero binario más grande (numPosiblesCombinaciones)
  let maxLengthBinary = decimalBinario(numPosiblesCombinaciones).split('').length

  for (let i = 0; i <= numPosiblesCombinaciones; i++) {
    // Convertimos el numero decimal(i) a binario
    let binary = decimalBinario(i, maxLengthBinary).split('').reverse()
    let result = []

    // si en la posicion i del numero binario hay un 1, agregamos el elemento
    // en la posicion i del arreglo arr al arreglo result
    for (let j = 0; j < binary.length; j++) {
      if (binary[j] === '1') {
        result.push(arr[j])
        // se va sumando el valor de cada elemento del subconjunto
        suma += arr[j]
      }
    }
    console.log(`{${result}} -> $${suma}`)
    // se reinicia la suma para el siguiente subconjunto
    suma = 0
  }
}

tablaBinaria(monedas, length)
