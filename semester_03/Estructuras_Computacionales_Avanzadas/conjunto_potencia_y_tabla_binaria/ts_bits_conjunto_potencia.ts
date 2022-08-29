const arr: string[] = ['a', 'b', 'c']
const arrLength: number = arr.length

const tamConjuntoPotencia: number = Math.pow(2, arrLength)

for (let i = 0; i < tamConjuntoPotencia; i++) {
  let conjuntoBinario: string[] = []
  let conjuntoPotencia: string[] = []

  for (let j = 0; j < arrLength; j++) {
    if (i & (1 << j)) {
      conjuntoBinario.push('1')
      conjuntoPotencia.push(arr[j])
    } else {
      conjuntoBinario.push('0')
    }
  }

  console.log(conjuntoBinario.join(' ') + ' -> ' + conjuntoPotencia.join(' '))

  conjuntoBinario.length = 0
  conjuntoPotencia.length = 0
}
