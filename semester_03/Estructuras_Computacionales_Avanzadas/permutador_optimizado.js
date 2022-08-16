// Diego Emilio Moreno Sanchez
// Lenguaje: javascript
// Path: permutador_de_n_en_r.js

// Definicion de los valores de entrada
const arr = ['a', 'b', 'c', 'd']  // -> conjunto de elementos a permutar
const n = arr.length              // -> cantidad de elementos a permutar
const r = 4                       // -> cantidad de elementos tomados (0 < r <= n)       

const permutador = (inputArr, r) => {
  let permutacionesResultantes = []      // -> array que almacena las permutaciones resultantes

  // Para cada arreglo en el array, crear un nuevo arreglo que es una copia del original,
  // pero con el elemento actual removido, y luego llamar a la funcion recursiva sobre ese 
  // nuevo arreglo, mientras tambien agregar el elemento actual a la lista de permutaciones.
  const permutar = (arr, r, m = []) => {
    // En algun punto de la recursion, si el arreglo es vacio, 
    // agregarlo a la lista de permutaciones
    console.log('arr', arr)
    console.log('m', m)
    if (m.length === r) {
      permutacionesResultantes.push(m)
    } else {
      for (let i = 0; i < arr.length; i++) {
        let actual = arr.slice()                      // -> copia del arreglo original
        let siguiente = actual.splice(i, 1)           // -> remover el elemento actual del arreglo
        permutar(actual.slice(), r, m.concat(siguiente)) // -> llamar a la funcion recursiva sobre el nuevo arreglo
      }
    }
  }

  permutar(inputArr, r)

  return permutacionesResultantes
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
const result = permutador(arr, r)

console.log(result)
console.log(permutaciones)