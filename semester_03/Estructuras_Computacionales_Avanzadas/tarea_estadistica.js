const array = ['aaa', 'aas', 'asa', 'ass', 'saa', 'sas', 'ssa', 'sss']
const length = array.length

const tam_conjuntoPotencia = Math.pow(2, length)

for (let i = 0; i < tam_conjuntoPotencia; i++) {
  let conjuntoPotencia = []
  for (let j = 0; j < length; j++) {
    // Hacemos la comparacion de bits
    if (i & (1 << j)) {
      conjuntoPotencia.push(array[j])
    }
  }
  console.log('{' + conjuntoPotencia.join(', ') + '}' + ' -> ' + (conjuntoPotencia.length) + ' -> ' + (conjuntoPotencia.length / array.length))
  conjuntoPotencia.length = 0
}
console.log(tam_conjuntoPotencia)
