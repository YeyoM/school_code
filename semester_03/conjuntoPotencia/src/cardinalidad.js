import getConjuntoPotencia from "./conjuntoPotencia"

export default function getCardinalidad(array) {
  let conjuntoPotencia = getConjuntoPotencia(array)
  let cardinalidad = []
  conjuntoPotencia.map((subconjunto) => {
    cardinalidad.push(subconjunto.length)
  })
  return cardinalidad
}