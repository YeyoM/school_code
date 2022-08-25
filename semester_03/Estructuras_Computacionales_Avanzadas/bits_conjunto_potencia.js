const array = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u']
const length = array.length

const tam_conjuntoPotencia = Math.pow(2, length)

for (let i = 0; i < tam_conjuntoPotencia; i++) {
  let conjuntoBin = []
  let conjuntoPotencia = []
  for (let j = 0; j < length; j++) {
    if (i & (1 << j)) {
      conjuntoBin.push('1')
      conjuntoPotencia.push(array[j])
    } else {
      conjuntoBin.push('0')
    }
  }
  console.log(conjuntoBin.join(' ') + ' -> {' + conjuntoPotencia.join(', ') + '}')
  conjuntoBin.length = 0
  conjuntoPotencia.length = 0
}
console.log(tam_conjuntoPotencia)