/**
 * Crea la tabla binaria de N elementos y relaciónalo al conjunto 
 * de elementos dados por el usuario para crear el conjunto potencia. 
 * También indica la frecuencia de aparición de cada elemento 
 * del conjunto en el conjunto potencia. 
 * Algoritmo: 
 * 1. Crear la tabla binaria de N elementos.
 * 2. Recorrer la tabla binaria y relacionarla con el conjunto de
 *    elementos dados por el usuario para crear el conjunto potencia.
 * 3. Recorrer el conjunto potencia y contar la frecuencia de aparición
 *    de cada elemento del conjunto en el conjunto potencia.
 * 4. Imprimir la frecuencia de aparición de cada elemento del conjunto
 *    en el conjunto potencia.
*/

// Esta parte del codigo es solo para aceptar input del usuario
// Este código no es necesario para la solución del problema
// pero si para probarlo con input del usuario

'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
  inputString += inputStdin;
});

process.stdin.on('end', _ => {
  inputString = inputString.trim().split('\n').map(string => {
    return string.trim();
  });
  main();    
});

function readline() {
  return inputString[currentLine++];
}

// ********** Inicio de código **********

function main() {

  // Ingresamos el numero de elementos del conjunto
  let n = parseInt(readline());

  // Ingresamos los elementos del conjunto
  let arr = readline().split(' ');

  // Creamos un objeto que contendrá la frecuencia de aparición
  // de cada elemento del conjunto
  let frecuencia = {
    // Lo que se hace en esta parte es recorrer el array(arr.reduce()) ingresado 
    // y por cada elemento del array se crea una propiedad en el objeto
    // con el nombre del elemento y el valor de esa propiedad es 0 que
    // representa la frecuencia de aparición de ese elemento en el conjunto
    ...arr.reduce((acc, el) => {
      acc[el] = 0;
      return acc;
    }, {})
  }

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

  // Formula de numero de combinaciones posibles de un conjunto
  const numPosibleCombinaciones = (length) => {
    return Math.pow(2, length)
  }

  // Creamos la tabla binaria de N elementos
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
        }
      }
      // Imprimimos el conjunto potencia
      console.log(binary, result)
      // Sumamos 1 a la frecuencia de aparición de cada elemento del conjunto
      result.map(item => {
        frecuencia[item]++
      })
    }
  }

  // Llamamos a la funcion tablaBinaria
  tablaBinaria(arr, n)
  // Imprimimos la frecuencia de aparición de cada elemento del conjunto
  console.log(frecuencia)
}