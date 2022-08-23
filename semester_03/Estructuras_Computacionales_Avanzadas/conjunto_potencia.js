// Diego Emilio Moreno Sanchez
// Lenguaje: javascript
// Path: conjunto_potencia.js

// Definicion de los valores de entrada
const arr = ['a', 'b', 'c']  // -> conjunto de elementos
const n = arr.length              // -> numero de elementos del conjunto

// Elimina los elementos duplicados de un array de arrays
const eliminarDuplicados = (arr) => {

  let ordenado = arr.map(arr => arr.sort())     // -> ordenamos los arrays, de tal modo que los que 
                                                //    tienen los mismos elementos sean iguales
  let stringArr = ordenado.map(JSON.stringify)  // -> convertir el array a string  
  let setUnicoArray = new Set(stringArr)        // -> convertir el string a un set
                                                //    ya que un set no permite elementos duplicados
                                                //    y los elimina automaticamente
  let sinDuplicadosArray = Array.from(
    setUnicoArray, 
    JSON.parse
  )                                             // -> convertir el set a un array 

  return sinDuplicadosArray.sort()              // -> retornar el array sin duplicados y "ordenado"        
}

const conjuntoPotencia = (inputArr) => {
  let conjuntoPotenciaParcial = []  
  let conjuntoPotencia = []

  // Para cada elemento en el array, crear un nuevo arreglo que es una copia del original,
  // pero con el elemento actual removido, y luego llamar a la funcion recursiva sobre ese 
  // nuevo arreglo, mientras tambien agregar el elemento actual a la lista de permutaciones.
  const combinar = (arr, m = []) => {
    conjuntoPotenciaParcial.push(m)
    conjuntoPotenciaParcial.push(arr)
    // el punto de salida es cuando el arreglo esta vacio
    for (let i = 0; i < arr.length; i++) {
      let actual = arr.slice()                      // -> copia del arreglo original
      let siguiente = actual.splice(i, 1)           // -> remover el elemento actual del arreglo
      // console.log(actual.slice(), m.concat(siguiente)) // -> imprimir los argumentos para la funcion
      combinar(actual.slice(), m.concat(siguiente)) // -> llamar a la funcion recursiva sobre el nuevo arreglo
    }
  }

  combinar(inputArr)
  // console.log(conjuntoPotenciaParcial)
  // Eliminamos los elementos duplicados de la lista de permutaciones parciales
  conjuntoPotencia = eliminarDuplicados(conjuntoPotenciaParcial)

  return conjuntoPotencia
}

// Funcion que calcula el numero de subconjuntos de un conjunto de elementos
const subconjuntos = (n) => {
  return Math.pow(2, n)
}

const result = conjuntoPotencia(arr)
const resultSubConjuntos = subconjuntos(n)

console.log(result)
console.log(resultSubConjuntos)
