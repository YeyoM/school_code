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
  for (let i = 0; i < matrix.length; i++) {
    let row = matrix[i]
    for (let j = 0; j < row.length; j++) {
      if (row[j] === 1 && i !== j) {
        let newRow = combineRows(matrix[i], matrix[j])
        matrix[i] = newRow
      }
    }
  }
}

const combineRows = (originalRow, rowToCombine) => {
  const newRow = originalRow.map((value, i) => {
    if (value === 1 || rowToCombine[i] === 1) {
      return 1
    } else {
      return 0
    }
  })
  return newRow
}


const main = () => { 

  const matrix = [
    [0, 1, 0, 0, 0],
    [0, 1, 1, 0, 0],
    [0, 0, 0, 1, 0],
    [0, 1, 0, 0, 1],
    [0, 0, 0, 0, 0]
  ]

  const newMatrix = addLeadDiagonal(matrix)
  console.log(newMatrix)

}

main()
