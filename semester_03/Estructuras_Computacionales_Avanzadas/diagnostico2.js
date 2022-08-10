const arr = ['a', 'b', 'c', 'd']
const n = arr.length

for (let i = 0; i < n; i++) {
  // aqui hacemos j = (i + 1) por que no queremos elementos repetidos
  // lo que es lo mismo no volver a comparar el elemento en la posicion
  // 1 con 2, cuando ya comparamos 2 con 1
  for (let j = (i + 1); j < n; j++) {
    console.log(arr[i], arr[j])
  }
}
