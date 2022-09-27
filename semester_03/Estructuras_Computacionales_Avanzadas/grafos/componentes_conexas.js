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

const countOnes = (row) => {
  let count = 0
  for (let i = 0; i < row.length; i++) {
    if (row[i] === 1) {
      count++
    }
  }
  return count
}

const getNodesCount = (matrix) => {
  let nodesCount = []
  for (let i = 0; i < matrix.length; i++) {
    let row = matrix[i]
    let count = countOnes(row)
    nodesCount.push(count)
  }
  return nodesCount
}

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

// check if there are other coordinates with the i or j value
// if there are, then they are part of the same component
// if not, then they are part of different components
// function here...
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
