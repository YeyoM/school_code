function generarAleatorio(min, max) {
  return Math.floor(Math.random() * (max - min)) + min
}

function cambiarPosicion() {
  const objeto = document.querySelector('.objeto')
  const container = document.querySelector('.container')
  const containerWidth = container.offsetWidth
  const containerHeight = container.offsetHeight
  const objetoWidth = objeto.offsetWidth
  const objetoHeight = objeto.offsetHeight
  const nuevoX = generarAleatorio(0, containerWidth - objetoWidth)
  const nuevoY = generarAleatorio(0, containerHeight - objetoHeight)
  objeto.style.left = `${nuevoX}px`
  objeto.style.top = `${nuevoY}px`
}

let objeto = document.querySelector('.objeto')
objeto.addEventListener('click', cambiarPosicion)