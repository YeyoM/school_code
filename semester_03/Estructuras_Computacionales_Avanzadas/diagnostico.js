// Crear un algoritmo que muestre las 
// combinaciones de un conjunto

const arr = ['a', 'b', 'c']
const n = arr.length

for (let i = 0; i < arr.length; i++) {
  for (let j = 0; j < arr.length; j++) {
    if (i !== j) {
      console.log(`${arr[i]}${arr[j]}`)
    }
  }
}
