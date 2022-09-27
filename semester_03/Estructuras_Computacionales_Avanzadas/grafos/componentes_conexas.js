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
const addLeadDiagonal = (matrix) => {
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
const generatePathMatrix = (matrix) => {
  let nodesVisitedInRow = Array(matrix.length).fill(0)
  for (let i = 0; i < matrix.length; i++) {
    let row = matrix[i]
    for (let j = 0; j < row.length; j++) {
      let row = matrix[i]
      if (row[j] === 1 && i !== j) {
        let newRow = combineRows(matrix[i], matrix[j])
        matrix[i] = newRow
        nodesVisitedInRow[i] = 1
      }
    }
    for (let k = row.length; k >= 0; k--) {
      if (matrix[i][k] === 1 && i !== k) {
        let newRow = combineRows(matrix[i], matrix[k])
        matrix[i] = newRow
        nodesVisitedInRow[i] = 1
      }
    }
  }
  return matrix
}

/**
 * Toma dos arreglos de la misma longitud y devuelve un nuevo arreglo donde cada elemento es 1 si
 * cualquiera de los elementos originales es 1, y 0 en caso contrario.
 * @param originalRow - la fila original 
 * @param rowToCombine - la fila a combinar
 * @returns Un nuevo arreglo con los valores combinados de los dos arreglos.
 */
const combineRows = (originalRow, rowToCombine) => {
  let newRow = originalRow.map((value, i) => {
    if (value === 1 || rowToCombine[i] === 1) {
      return 1
    } else {
      return 0
    }
  })
  return newRow
}

/**
 * Toma una fila de números y devuelve la cantidad de unos en esa fila.
 * @param row - la fila del tablero que estás revisando
 * @returns La cantidad de 1's en la fila.
 */
const countOnes = (row) => {
  let count = 0
  for (let i = 0; i < row.length; i++) {
    if (row[i] === 1) {
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
const getNodesCount = (matrix) => {
  let nodesCount = []
  for (let i = 0; i < matrix.length; i++) {
    let row = matrix[i]
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
const getNodesOrder = (nodesCount) => {
  let nodesOrder = []
  for (let i = 0; i < nodesCount.length; i++) {
    let max = Math.max(...nodesCount)
    let index = nodesCount.indexOf(max)
    nodesOrder.push(index)
    nodesCount[index] = -1
  }
  return nodesOrder
}

/**
 * Toma una matriz y devuelve una matriz con las mismas filas, pero ordenadas por la cantidad de unos en cada
 * fila.
 * @param matrix - la matriz a ordenar
 * @returns una matriz ordenada.
 */
const sortMatrixOnes = (matrix) => {
  let nodesCount = getNodesCount(matrix)
  let sortedMatrix = []
  for (let i = 0; i < nodesCount.length; i++) {
    let max = Math.max(...nodesCount)
    let index = nodesCount.indexOf(max)
    sortedMatrix.push(matrix[index])
    nodesCount[index] = -1
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
const sortMatrixColumns = (matrix, nodesOrder) => {
  let copyMatrix = matrix.map((row) => {
    return row.slice()
  })
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < matrix.length; j++) {
      matrix[i][j] = copyMatrix[i][nodesOrder[j]]
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
const getUnderDiagonalNodes = (matrix) => {
  let coordinates = []
  for (let i = 0; i < matrix.length; i++) {
    for (let j = 0; j < i; j++) {
      if (matrix[i][j] === 1) {
        coordinates.push([i, j])
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
const divideComponents = (coordinates) => {
  let components = []
  for (let i = 0; i < coordinates.length; i++) {
    let component = []
    for (let j = 0; j < coordinates.length; j++) {
      if (coordinates[i][0] === coordinates[j][0] || coordinates[i][1] === coordinates[j][1]) {
        component.push(coordinates[j])
      }
    }
    components.push(component)
  }

  for (let i = 0; i < components.length; i++) {
    for (let j = 0; j < components.length; j++) {
      if (i !== j) {
        let component1 = components[i]
        let component2 = components[j]
        let component1String = component1.toString()
        let component2String = component2.toString()
        if (component1String.includes(component2String)) {
          components.splice(j, 1)
        } else if (component2String.includes(component1String)) {
          components.splice(i, 1)
        }
      }
    }
  }

  return components

}

/**
 * Toma una matriz y una lista de componentes parciales y devuelve una lista de componentes.
 * @param matrix - la matriz de adyacencia
 * @param partialComponents - array de arrays de coordenadas de nodos que están conectados entre sí
 * @returns Un array de arrays. Cada array contiene los nodos que forman un componente de la matriz de caminos
 */
const getComponentesConexas = (matrix, partialComponents) => {

  let diagonalNodesVisited = Array(matrix.length).fill(0)
  let componentesConexas = []
  let nodesInPartialComponent = []
  
  // get the nodes in the partial components
  for (let i = 0; i < partialComponents.length; i++) {
    let component = partialComponents[i]
    for (let j = 0; j < component.length; j++) {
      let node = component[j]
      nodesInPartialComponent.push(node[0])
      nodesInPartialComponent.push(node[1])
      diagonalNodesVisited[node[0]] = 1
      diagonalNodesVisited[node[1]] = 1
      nodesInPartialComponent = [...new Set(nodesInPartialComponent)]
    }
    componentesConexas.push(nodesInPartialComponent)
    // clear the nodesInPartialComponent array
    nodesInPartialComponent = []
  }

  do {
    for (let i = 0; i < diagonalNodesVisited.length; i++) {
      if (diagonalNodesVisited[i] === 0) {
        let component = []
        component.push(i)
        diagonalNodesVisited[i] = 1
        componentesConexas.push(component)
      }
    }
  } while (diagonalNodesVisited.includes(0))

  return componentesConexas
  
}

const main = () => { 

  let matrix = [
    [0, 0, 0, 1, 1, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 1],
    [1, 1, 1, 0, 0, 0],
    [0, 1, 1, 0, 0, 1],
    [0, 0, 0, 0, 1, 0]
  ]

  const newMatrix = addLeadDiagonal(matrix)
  console.log(newMatrix)

  const pathMatrix = generatePathMatrix(newMatrix)
  console.log(pathMatrix)

  const sortedMatrix = sortMatrixOnes(pathMatrix)
  console.log(sortedMatrix)

  let nodesCount = getNodesCount(pathMatrix)

  let nodesOrder = getNodesOrder(nodesCount)

  let sortedMatrixColumns = sortMatrixColumns(sortedMatrix, nodesOrder)
  console.log(sortedMatrixColumns)

  let underDiagonalNodes = getUnderDiagonalNodes(sortedMatrixColumns)

  let components = divideComponents(underDiagonalNodes)

  let componentesConexas = getComponentesConexas(sortedMatrixColumns, components)
  console.log("Las componentes conexas del grafo son: ", componentesConexas)
}

main()
