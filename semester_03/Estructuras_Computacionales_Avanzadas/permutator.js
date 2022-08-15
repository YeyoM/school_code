// Diego Emilio Moreno Sanchez
// Lenguaje: javascript
// Path: permutator.js

// Definicion de los valores de entrada
const arr = ['a', 'b', 'c', 'd']  // -> conjunto de elementos a permutar
const n = arr.length              // -> cantidad de elementos a permutar
const r = 3                       // -> cantidad de elementos tomados (0 < r <= n)       

// Elimina los elementos duplicados de un array de arrays
const deleteDuplicates = (arr) => {
  let stringArray = arr.map(JSON.stringify)     // -> convertir el array a string         
  let uniqueStringArray = new Set(stringArray)  // -> convertir el string a un set
  let uniqueArray = Array.from(
    uniqueStringArray, 
    JSON.parse
  )                                             // -> convertir el set a un array sin duplicados           
  return uniqueArray                            // -> retornar el array sin duplicados          
}

const permutator = (inputArr, r) => {
  let allPermutations = []        // -> array que almacena todas las permutaciones
  let partialPermutations = []    // -> array que almacena las permutaciones parciales
  let resultedPermutations = []   // -> array que almacena las permutaciones resultantes

  // Para cada arreglo en el array, crear un nuevo arreglo que es una copia del original,
  // pero con el elemento actual removido, y luego llamar a la funcion recursiva sobre ese 
  // nuevo arreglo, mientras tambien agregar el elemento actual a la lista de permutaciones.
  const permute = (arr, m = []) => {
    // En algun punto de la recursion, si el arreglo es vacio, 
    // agregarlo a la lista de permutaciones
    if (arr.length === 0) {
      allPermutations.push(m)
    } else {
      for (let i = 0; i < arr.length; i++) {
        let curr = arr.slice()                  // -> copia del arreglo original
        let next = curr.splice(i, 1)            // -> remover el elemento actual del arreglo
        permute(curr.slice(), m.concat(next))  // -> llamar a la funcion recursiva sobre el nuevo arreglo
      }
    }
  }

  permute(inputArr)

  // Eliminamos el excedente de elementos tomados por permutacion
  // ejemplo, si r = 3, y el tamaño del arreglo es 4, eliminamos
  // de cada permutacion el ultimo elemento (n - r)
  allPermutations.map((arr) => {
    let sliced = arr.slice(0, r)        // -> cortamos el arreglo desde el primer elemento hasta el r-esimo
    partialPermutations.push(sliced)    // -> agregamos el arreglo a la lista de permutaciones parciales
  })
  
  // Eliminamos los elementos duplicados de la lista de permutaciones parciales
  resultedPermutations = deleteDuplicates(partialPermutations)

  return resultedPermutations;
}

// Funcion que calcula el factorial de un numero
const factorial = (n) => {
  if (n === 0) {
    return 1
  } else if (n === 1) {
    return n
  } else {
    return n * factorial(n - 1)
  }
}

// Funcion que calcula el numero de permutaciones de un conjunto de elementos tomados r
const permutacion = (n, r) => {
  return (factorial(n) / factorial(n - r))
}

const permutaciones = permutacion(n, r)
const result = permutator(arr, r)

console.log(result)
console.log(permutaciones)