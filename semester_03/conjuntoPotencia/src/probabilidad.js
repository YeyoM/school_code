import getConjuntoPotencia from "./conjuntoPotencia"

export default function getProbabilidad(arr) {
  let conjuntoPotencia = getConjuntoPotencia(arr)
  let probabilidad = []
  conjuntoPotencia.map((subconjunto) => {
    probabilidad.push(subconjunto.length / arr.length)
  })
  return probabilidad
}