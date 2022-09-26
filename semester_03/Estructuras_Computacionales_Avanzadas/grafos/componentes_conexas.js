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

const getComponentesConexas = (matrix) => {
  
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
}

main()
