const array = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u']
const length = array.length

const tam_conjuntoPotencia = Math.pow(2, length)

// complejidad Algoritmica de O(n2)
for (let i = 0; i < tam_conjuntoPotencia; i++) {
  let conjuntoBin = []
  let conjuntoPotencia = []
  for (let j = 0; j < length; j++) {
    // Hacemos la comparacion de bits
    if (i & (1 << j)) {
      // en caso de que se cumpla añadimos un 1 al array que será el num en binario
      conjuntoBin.push('1')
      // y al mismo tiempo añadimos al conjunto potencia el elemento del arr en la pos j
      conjuntoPotencia.push(array[j])
    } else {
      // en caso contrario añadimos al array del num binario un 0
      conjuntoBin.push('0')
    }
  }
  // mostramos el resultado numBinario -> { conjuntoPotencia }
  console.log(conjuntoBin.join(' ') + ' -> {' + conjuntoPotencia.join(', ') + '}')
  // Limpiamos los arreglos para eliminarlos de la memoria
  conjuntoBin.length = 0
  conjuntoPotencia.length = 0
}
console.log(tam_conjuntoPotencia)
