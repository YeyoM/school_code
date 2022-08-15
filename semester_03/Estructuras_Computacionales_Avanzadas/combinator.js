// Diego Emilio Moreno Sanchez
// Lenguaje: javascript
// Path: permutator.js

// Definicion de los valores de entrada
const arr = ['a', 'b', 'c', 'd']  // -> conjunto de elementos a permutar
const n = arr.length              // -> cantidad de elementos a permutar
const r = 2                       // -> cantidad de elementos tomados (0 < r <= n)       

// Elimina los elementos duplicados de un array de arrays
const eliminarDuplicados = (arr) => {

  let ordenado = arr.map(arr => arr.sort())     // -> ordenamos los arrays, de tal modo que los que 
                                                //    tienen los mismos elementos sean iguales
  let stringArr = ordenado.map(JSON.stringify)  // -> convertir el array a string  
  let setUnicoArray = new Set(stringArr)        // -> convertir el string a un set
                                                // ya que un set no permite elementos duplicados
                                                // y los elimina automaticamente
  let sinDuplicadosArray = Array.from(
    setUnicoArray, 
    JSON.parse
  )                                             // -> convertir el set a un array sin duplicados  

  return sinDuplicadosArray                     // -> retornar el array sin duplicados          
}

const combinador = (inputArr, r) => {
  let combinacionesPosibles = []         // -> array que almacena todas las permutaciones
  let combinacionesParciales = []        // -> array que almacena las permutaciones parciales
  let combinacionesResultantes = []      // -> array que almacena las permutaciones resultantes

  // Para cada arreglo en el array, crear un nuevo arreglo que es una copia del original,
  // pero con el elemento actual removido, y luego llamar a la funcion recursiva sobre ese 
  // nuevo arreglo, mientras tambien agregar el elemento actual a la lista de permutaciones.
  const combinar = (arr, m = []) => {
    // En algun punto de la recursion, si el arreglo es vacio, 
    // agregarlo a la lista de permutaciones
    if (arr.length === 0) {
      combinacionesPosibles.push(m)
    } else {
      for (let i = 0; i < arr.length; i++) {
        let actual = arr.slice()                      // -> copia del arreglo original
        let siguiente = actual.splice(i, 1)           // -> remover el elemento actual del arreglo
        combinar(actual.slice(), m.concat(siguiente)) // -> llamar a la funcion recursiva sobre el nuevo arreglo
      }
    }
  }

  combinar(inputArr)

  // Eliminamos el excedente de elementos tomados por permutacion
  // ejemplo, si r = 3, y el tamaño del arreglo es 4, eliminamos
  // de cada permutacion el ultimo elemento (n - r)
  combinacionesPosibles.map((arr) => {
    let sliced = arr.slice(0, r)        // -> cortamos el arreglo desde el primer elemento hasta el r-esimo
    combinacionesParciales.push(sliced)  // -> agregamos el arreglo a la lista de permutaciones parciales
  })
  
  // Eliminamos los elementos duplicados de la lista de permutaciones parciales
  combinacionesResultantes = eliminarDuplicados(combinacionesParciales)

  return combinacionesResultantes
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

// Funcion que calcula el numero de combinaciones de un conjunto de elementos tomados r
const combinacion = (n, r) => {
  return (factorial(n) / (factorial(n - r) * factorial(r)))
}

const combinaciones = combinacion(n, r)
const result = combinador(arr, r)

console.log(result)
console.log(combinaciones)