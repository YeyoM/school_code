export default function getConjuntoPotencia(array) {
  let conjuntoPotencia = [[]];
  const length = array.length

  const tam_conjuntoPotencia = Math.pow(2, length)

  for (let i = 0; i < tam_conjuntoPotencia; i++) {
    let subconjunto = []
    for (let j = 0; j < length; j++) {
      // Hacemos la comparacion de bits
      if (i & (1 << j)) {
        subconjunto.push(array[j])
      }
    }
    if (i !== 0) {
      conjuntoPotencia.push(subconjunto)
    }
  }
  
  return conjuntoPotencia

}