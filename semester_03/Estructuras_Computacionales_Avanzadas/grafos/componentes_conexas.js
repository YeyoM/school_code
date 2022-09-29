/**
 * Autor: Diego Moreno @YeyoM
 * Fecha: 27/09/2022
 * Descripción: Algoritmo para encontrar las componentes conexas de un grafo de caminos
 * @param {Array} matrix Matriz de adyacencia del grafo
 * @returns {Array} Componentes conexas del grafo
 * @example
 * let matrix = [
 *  [0, 0, 0, 1, 1, 0],
 *  [0, 0, 0, 0, 0, 0],
 *  [0, 0, 0, 0, 0, 1],
 *  [1, 1, 1, 0, 0, 0],
 *  [0, 1, 1, 0, 0, 1],
 *  [0, 0, 0, 0, 1, 0]
 * ]
 * 
 * Procedimiento basado en el video de Jmq Mattosky: Componentes conexas de un grafo 02
 * (https://www.youtube.com/watch?v=1faJmdEd0rU)
 * 
 * 1. Agregar la diagonal principal
 * 2. Generar la matriz de caminos
 * 3. Ordenar la matriz de caminos por cantidad de unos en filas
 * 4. Ordenar las columnas de la matriz de caminos por cantidad de unos en columnas
 * 5. Obtener las coordenadas de los nodos que están debajo de la diagonal
 * 6. Obtener las componentes conexas
 * 
 */

/**
 * Toma una matriz y devuelve la misma matriz con 1´s en la diagonal principal.
 * @param matrix - la matriz a la que se le agregará la diagonal
 * @returns Una nueva matriz con la diagonal principal establecida en 1.
 */
function addLeadDiagonal(matrix) {
  const newMatrix = matrix.map((row, i) => {
    const newRow = row.map((value, j) => {
      if (i === j) {
        return 1
      } else {
        return value
      }
    })
    return newRow
  })
  return newMatrix
}

/**
 * Toma una matriz y devuelve la matriz de caminos
 * Donde cada fila es la combinación de todas las filas que tienen un 1 en la misma columna que la fila actual.
 * @param matrix - la matriz de adyacencia
 * @returns Una matriz con el camino más corto entre cada nodo. 
 */
function generatePathMatrix(matrix) {
  // Este array nos servirá para que cuando recorramos el array de regreso
  // Evitemos combinar filas que ya fueron combinadas.
  let nodesVisitedInRow = Array(matrix.length).fill(0)

  // Recorremos la matriz por filas 
  for (let i = 0; i < matrix.length; i++) {
    // Guardamos la fila actual
    let row = matrix[ i ]

    // Recorremos cada elemento de la fila
    for (let j = 0; j < row.length; j++) {
      // Volvemos a guardar la fila actual de nuevo (actualizar la referencia)
      let row = matrix[ i ]
      // Si el elemento j de la fila es 1 y no está en la diagonal principal
      if (row[ j ] === 1 && i !== j) {
        // Combinamos la fila actual con la fila j
        let newRow = combineRows(matrix[ i ], matrix[ j ])
        // Guardamos la nueva fila en la matriz
        matrix[ i ] = newRow
        // Marcamos el nodo i como visitado
        nodesVisitedInRow[ i ] = 1
      }
    }

    // Recorremos la misma fila de regreso
    for (let k = row.length; k >= 0; k--) {
      // Si el elemento k de la fila es 1 y no está en la diagonal principal y no ha sido visitado
      if (matrix[ i ][ k ] === 1 && i !== k && nodesVisitedInRow[ k ] === 0) {
        // Combinamos la fila actual con la fila k
        let newRow = combineRows(matrix[ i ], matrix[ k ])
        // Guardamos la nueva fila en la matriz
        matrix[ i ] = newRow
        // Marcamos el nodo i como visitado
        nodesVisitedInRow[ i ] = 1
      }
    }
  }

  // retornamos la matriz de caminos
  return matrix
}

/**
 * Toma dos arreglos de la misma longitud y devuelve un nuevo arreglo donde cada elemento es 1 si
 * cualquiera de los elementos originales es 1, y 0 en caso contrario.
 * @param originalRow - la fila original 
 * @param rowToCombine - la fila a combinar
 * @returns Un nuevo arreglo con los valores combinados de los dos arreglos.
 */
function combineRows(originalRow, rowToCombine) {
  // Recorremos el arreglo original (fila actual)
  let newRow = originalRow.map((value, i) => {
    // Si el elemento i de la fila actual es 1 o el elemento i de la fila a combinar es 1
    if (value === 1 || rowToCombine[ i ] === 1) {
      // Retornamos 1 en la nueva fila (posición i)
      return 1
    } else {
      // Retornamos 0 en la nueva fila (posición i)
      return 0
    }
  })
  // Retornamos la nueva fila
  return newRow
}

/**
 * Toma una fila de números y devuelve la cantidad de unos en esa fila.
 * @param row - la fila del tablero que estás revisando
 * @returns La cantidad de 1's en la fila.
 */
function countOnes(row) {
  let count = 0
  for (let i = 0; i < row.length; i++) {
    if (row[ i ] === 1) {
      count++
    }
  }
  return count
}

/**
 * Toma una matriz y devuelve un arreglo con la cantidad de unos en cada fila de la matriz.
 * @param matrix - la matriz de adyacencia
 * @returns Un arreglo con la cantidad de 1's en cada fila de la matriz.
 */
function getNodesCount(matrix) {
  let nodesCount = []
  for (let i = 0; i < matrix.length; i++) {
    let row = matrix[ i ]
    let count = countOnes(row)
    nodesCount.push(count)
  }
  return nodesCount
}

/**
 * Toma un arreglo de números y devuelve un arreglo con los índices de los elementos en orden descendente.
 * @param nodesCount - el array de 1's en cada fila de la matriz
 * @returns Un arreglo con los índices de los elementos en orden descendente. 
 */
function getNodesOrder(nodesCount) {
  // Creamos un arreglo con los índices de los elementos en orden descendente
  let nodesOrder = []
  // Recorremos el arreglo de 1's en cada fila de la matriz
  for (let i = 0; i < nodesCount.length; i++) {
    // Guardamos el elemento más grande en el arreglo
    let max = Math.max(...nodesCount)
    // Guardamos el índice del elemento más grande en el arreglo
    let index = nodesCount.indexOf(max)
    // Guardamos el índice del elemento más grande en el arreglo de índices
    nodesOrder.push(index)
    // Marcamos el elemento mayor como -1 para que no se vuelva a tomar en cuenta
    nodesCount[ index ] = -1
  }
  return nodesOrder
}

/**
 * Toma una matriz y devuelve una matriz con las mismas filas, pero ordenadas por la cantidad de unos en cada
 * fila.
 * @param matrix - la matriz a ordenar
 * @returns una matriz ordenada.
 */
function sortMatrixOnes(matrix) {
  // Obtenemos la cantidad de 1's en cada fila
  let nodesCount = getNodesCount(matrix)
  // Variable que guardará la matriz ordenada
  let sortedMatrix = []

  // Recorremos el arreglo de 1's
  for (let i = 0; i < nodesCount.length; i++) {
    // Obtenemos el elemento mayor en el arreglo de 1's
    let max = Math.max(...nodesCount)
    // Obtenemos el índice del elemento mayor en el arreglo de 1's
    let index = nodesCount.indexOf(max)
    // Guardamos la fila en la matriz ordenada del índice obtenido
    sortedMatrix.push(matrix[ index ])
    // Marcamos el elemento mayor como -1 para que no se vuelva a tomar en cuenta
    nodesCount[ index ] = -1
  }
  return sortedMatrix
}

/**
 * Toma una matriz y un arreglo de números, y devuelve una nueva matriz donde las columnas están ordenadas
 * de acuerdo al arreglo.
 * @param matrix - la matriz a ordenar
 * @param nodesOrder - array del orden de los nodos de manera descendente
 * @returns Una matriz con las columnas ordenadas por el orden de los nodos.
 */
function sortMatrixColumns(matrix, nodesOrder) {
  // Creamos una copia de la matriz
  let copyMatrix = matrix.map((row) => {
    return row.slice()
  })
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix.length; j++) {
      // En la matriz original guardamos el valor de la fila i, columna nodesOrder[j] (indice j de nodesOrder)
      matrix[ i ][ j ] = copyMatrix[ i ][ nodesOrder[ j ] ]
    }
  }
  return matrix
}

/**
 * Toma una matriz y devuelve un arreglo de las coordenadas de los nodos que se encuentren debajo de la 
 * diagonal principal.
 * @param matrix - una matriz de adyacencia
 * @returns Un arreglo de las coordenadas de los nodos que se encuentren debajo de la diagonal principal.
 */
function getUnderDiagonalNodes(matrix) {
  // Creamos un arreglo para guardar las coordenadas de los nodos que se encuentren debajo de la diagonal principal
  let coordinates = []
  // Recorremos la matriz
  for (let i = 0; i < matrix.length; i++) {
    // Pero solo por debajo de la diagonal principal (j < i)
    for (let j = 0; j < i; j++) {
      if (matrix[ i ][ j ] === 1) {
        // Guardamos las coordenadas de los nodos que se encuentren debajo de la diagonal principal
        coordinates.push([ i, j ])
      }
    }
  }
  return coordinates
}

/**
 * Toma un array de las coordenadas de nodos que se encuentran debajo de la diagonal principal de una matriz
 * y devuelve un array de arrays de coordenadas que están conectados entre sí.
 * @param coordinates - coordenadas de los nodos que se encuentran debajo de la diagonal principal
 * @returns Un array de arrays de coordenadas.
 */
function divideComponents(coordinates) {
  let components = []

  // Recorremos el arreglo de coordenadas
  for (let i = 0; i < coordinates.length; i++) {
    // Creamos una variable component para guardar las coordenadas de los nodos que están conectados entre sí
    let component = []
    // Vamos a comparar cada coordenada con las demás
    for (let j = 0; j < coordinates.length; j++) {
      // Si la coordenada i está conectada con la coordenada j
      if (coordinates[ i ][ 0 ] === coordinates[ j ][ 0 ] || coordinates[ i ][ 1 ] === coordinates[ j ][ 1 ]) {
        // Guardamos la coordenada j en el arreglo component
        component.push(coordinates[ j ])
      }
    }
    // Guardamos el componente en el arreglo components 
    components.push(component)
  }

  // Aqui siguen habiendo mas componentes de los que en realidad existen
  // Por lo que debemos juntarlos en grupos de componentes que estén conectados entre sí
  console.log(components)

  // Vamos a comparar cada grupo de componentes con los demás
  for (let i = 0; i < components.length; i++) {
    for (let j = 0; j < components.length; j++) {
      if (i !== j) {
        let component1 = components[ i ]
        let component2 = components[ j ]
        let component1String = component1.toString()
        let component2String = component2.toString()
        // Si el componente 1 está contenido en el componente 2
        if (component1String.includes(component2String)) {
          // Eliminamos el componente 1
          components.splice(j, 1)
        } 
        // Si el componente 2 está contenido en el componente 1
        else if (component2String.includes(component1String)) {
          // Eliminamos el componente 2
          components.splice(i, 1)
        }
      }
    }
  }

  // Retornamos el arreglo de componentes
  return components

}

/**
 * Toma una matriz y una lista de componentes parciales y devuelve una lista de componentes.
 * @param matrix - la matriz de adyacencia
 * @param partialComponents - array de arrays de coordenadas de nodos que están conectados entre sí
 * @returns Un array de arrays. Cada array contiene los nodos que forman un componente de la matriz de caminos
 */
function getComponentesConexas(matrix, partialComponents) {

  // Creamos un arreglo para guardar los nodos de la diagonal principal
  let diagonalNodesVisited = Array(matrix.length).fill(0)
  let componentesConexas = []
  let nodesInPartialComponent = []

  for (let i = 0; i < partialComponents.length; i++) {
    // Coordenadas de los nodos que están conectados entre sí
    let component = partialComponents[ i ]
    for (let j = 0; j < component.length; j++) {
      // Tomamos las 2 coordenadas de cada nodo y las guardamos en un arreglo
      let node = component[ j ]
      nodesInPartialComponent.push(node[ 0 ])
      nodesInPartialComponent.push(node[ 1 ])
      diagonalNodesVisited[ node[ 0 ] ] = 1
      diagonalNodesVisited[ node[ 1 ] ] = 1
      // Cada arreglo mostrará los nodos que forman un componente de la matriz de caminos
      // Por lo que debemos eliminar los nodos repetidos
      nodesInPartialComponent = [ ...new Set(nodesInPartialComponent) ]
    }
    componentesConexas.push(nodesInPartialComponent)
    // clear the nodesInPartialComponent array
    nodesInPartialComponent = []
  }

  // Por ultimo recorremos el arreglo diagonalNodesVisited
  // Para ver si hay nodos que no estén en los componentes parciales
  // Esos nodos forman un componente de la matriz de caminos (ellos solos)
  do {
    for (let i = 0; i < diagonalNodesVisited.length; i++) {
      if (diagonalNodesVisited[ i ] === 0) {
        let component = []
        component.push(i)
        diagonalNodesVisited[ i ] = 1
        componentesConexas.push(component)
      }
    }
  } while (diagonalNodesVisited.includes(0))

  return componentesConexas

}

function main() {

  let matrix = [
    [ 0, 0, 0, 1, 1, 0 ],
    [ 0, 0, 0, 0, 0, 0 ],
    [ 0, 0, 0, 0, 0, 1 ],
    [ 1, 1, 1, 0, 0, 0 ],
    [ 0, 1, 1, 0, 0, 1 ],
    [ 0, 0, 0, 0, 1, 0 ]
  ]

  // let matrix = [
  //   [0, 1, 0, 0, 0],
  //   [0, 1, 1, 0, 0],
  //   [0, 0, 0, 1, 0],
  //   [0, 1, 0, 0, 1],
  //   [0, 0, 0, 0, 0]
  // ]

  const newMatrix = addLeadDiagonal(matrix)
  console.log("Matriz con diagonal principal: ", newMatrix)

  const pathMatrix = generatePathMatrix(newMatrix)
  console.log("Matriz de caminos: ", pathMatrix)

  const sortedMatrix = sortMatrixOnes(pathMatrix)
  console.log("Matriz ordenada en filas: ", sortedMatrix)

  let nodesCount = getNodesCount(pathMatrix)

  let nodesOrder = getNodesOrder(nodesCount)

  let sortedMatrixColumns = sortMatrixColumns(sortedMatrix, nodesOrder)
  console.log("Matriz ordenada en filas y columnas: ", sortedMatrixColumns)

  let underDiagonalNodes = getUnderDiagonalNodes(sortedMatrixColumns)
  console.log("Coordenadas de nodos debajo de la diagonal: ", underDiagonalNodes)

  let components = divideComponents(underDiagonalNodes)
  console.log("Conjunto de nodos que forman una componente: ", components)

  let componentesConexas = getComponentesConexas(sortedMatrixColumns, components)
  console.log("Las componentes conexas del grafo son: ", componentesConexas)
}

main()
