/*
  Una persona dispone de un departamento que desea alquilar 
  durante el verano. Luego de publicarlo en los clasificados 
  obtiene N ofertas. Cada oferta consta de 3 datos: el monto ofrecido, 
  el día de inicio y el día de finalización. Esta persona desea 
  maximizar sus ganancias. Modelar el problema como un problema 
  de grafos y resolverlo con un algoritmo conocido.  
*/

/**
 * El planteamiento de como resolver el problema es el siguiente:
   Primero el problema lo vamos a ver como un grafo ponderado, dirigido
   y fuertemente conexo.
   Creamos la matriz de adyacencia de dicho grafo, cada nodo es una fecha
   y cada arista es una oferta. Todas las aristas que salgan de un nodo
   llevan el peso de la oferta de donde salen.
   La idea es que a paritr de ese grafo nos quede un arbol en forma de lista 
   donde cada nodo solo tiene una arista que sale y otra que llega a el.
   A excepcion del primer y ultimo nodo
   Los pasos para llegar a este resultado son los siguientes:
   1. Recorrer la matriz de adyacencia
   2. Para cada iteración vamos a verificar lo siguiente
    2.1. Si la arista es 0, no hacemos nada
    2.2. Vamos a revisar si las fechas de i, con j se cruzan
      2.2.1. Si se cruzan, vamos a ver cual es la mejor fecha (la que mas dinero da por dia)
      2.2.2. Vamos a eliminar la arista que no es la mejor (eleminar fila y columna de dicha fecha)
             de esta forma no tendra conexion con ningun nodo y se descarta
    2.3. Si no se cruzan
      2.3.1. Revisamos la fecha de salida de j es menor a la fecha de llegada de i
             esa casilla la marcamos como cero
   3. Una vez que terminamos de recorrer la matriz de adyacencia
      tenemos que dejar solo la fecha mas cercana a cierta fecha de salida de cada fila
     3.1 Esto lo logramos recorriengo otra vez la matriz de adyacencia
         y guardando cada fila en un array, vamos a comparar todas las fechas
         de llegada de cada fila y nos quedamos con la mas cercana
        a la fecha de salida de la fila 
   4. Una vez que tenemos el arbol en forma de lista, vamos a recorrerlo
      y vamos a ir sumando los montos de cada arista
   5. Retornamos el monto total con los datos de cada fecha elegida
 */

/**
 * Funcion que retorna si dos fechas se cruzan
 * @param {Date} fecha1Inicio
 * @param {Date} fecha1Fin
 * @param {Date} fecha2Inicio
 * @param {Date} fecha2Fin
 */
 function hayCruzamiento(fecha1, fecha2) {
  let fecha1Inicio = fecha1.fechaLlegada
  let fecha1Fin = fecha1.fechaSalida
  let fecha2Inicio = fecha2.fechaLlegada
  let fecha2Fin = fecha2.fechaSalida
  if (fecha1Inicio <= fecha2Fin && fecha1Fin >= fecha2Inicio) {
    return true
  }
}

/**
 * Funcion que retorna la mejor oferta entre dos ofertas (monto / dia)
 * @param {Object} oferta1
 * @param {Object} oferta2
 * @returns {Object} la mejor oferta
*/
function mejorFecha(fecha1, fecha2) {
  let fecha1Inicio = fecha1.fechaLlegada
  let fecha1Fin = fecha1.fechaSalida
  let fecha2Inicio = fecha2.fechaLlegada
  let fecha2Fin = fecha2.fechaSalida

  let monto1 = fecha1.montoOfrecido
  let monto2 = fecha2.montoOfrecido

  // obtenemos los dias de alojamiento de cada fecha
  let dias1 = Math.ceil((fecha1Fin - fecha1Inicio) / (1000 * 3600 * 24))
  let dias2 = Math.ceil((fecha2Fin - fecha2Inicio) / (1000 * 3600 * 24))

  // hacemos el calculo de los montos por dia
  let montoDia1 = monto1 / dias1
  let montoDia2 = monto2 / dias2

  // si el monto por dia de la fecha 1 es mayor
  if (montoDia1 > montoDia2) {
    // retornamos la fecha 1
    return fecha1.id
  } else {
    // si no, retornamos la fecha 2
    return fecha2.id
  }
}

let nodo0 = {
  // llegada: 15 de agosto 2022
  fechaLlegada: new Date(2022, 7, 15),
  // salida: 20 de agosto 2022
  fechaSalida: new Date(2022, 7, 20),
  montoOfrecido: 500,
  id: 0
}

let nodo1 = {
  // llegada: 22 de agosto 2022
  fechaLlegada: new Date(2022, 7, 22),
  // salida 30 de agosto 2022
  fechaSalida: new Date(2022, 7, 30),
  montoOfrecido: 2000,
  id: 1
}

let nodo2 = {
  // llegada: 15 de julio 2022
  fechaLlegada: new Date(2022, 6, 15),
  // salida: 17 de julio 2022
  fechaSalida: new Date(2022, 6, 17),
  montoOfrecido: 700,
  id: 2
}

let nodo3 = {
  // llegada 1 de agosto 2022
  fechaLlegada: new Date(2022, 7, 1),
  // salida 16 de agosto 2022
  fechaSalida: new Date(2022, 7, 16),
  montoOfrecido: 2300,
  id: 3
}

let nodo4 = {
  // llegada 18 Julio
  fechaLlegada: new Date(2022, 6, 18),
  // salida 2 de agosto 2022
  fechaSalida: new Date(2022, 7, 2),
  montoOfrecido: 2500,
  id: 4
}

let nodo5 = {
  // llegada 1 de diciembre 2022
  fechaLlegada: new Date(2022, 11, 1),
  // salida 12 de diciembre 2022
  fechaSalida: new Date(2022, 11, 12),
  montoOfrecido: 3000,
  id: 5
}

// creamos un array de todas las ofertas
let nodosArr = [nodo0, nodo1, nodo2, nodo3, nodo4, nodo5]

// inicializamos la matriz con solo ceros
let matrix = []
for (let i = 0; i < nodosArr.length; i++) {
  matrix[i] = new Array(nodosArr.length).fill(0)
}

// llenamos la matriz con los datos de las ofertas
for (let i = 0; i < nodosArr.length; i++) {
  for (let j = 0; j < nodosArr.length; j++) {
    if (i !== j) {
      matrix[i][j] = nodosArr[i].montoOfrecido
    }
  }
}

console.log(matrix)

let seCruza = false
let fechasCruzadas = []

for (let i = 0; i < nodosArr.length; i++) {
  for (let j = 0; j < nodosArr.length; j++) {
    // guardamos las ofertas en variables
    let fecha1 = nodosArr[i]
    let fecha2 = nodosArr[j]

    seCruza = hayCruzamiento(fecha1, fecha2)

    if (i !== j) {
      // si se cruzan
      if (seCruza) {
        fechasCruzadas.push(i)
        fechasCruzadas.push(j)
      }
      seCruza = false

    }
    
  }
}

// contar el elemento que mas se repite en fechasCruzadas
let max = 0
let maxId = 0
for (let i = 0; i < fechasCruzadas.length; i++) {
  let count = 0
  for (let j = 0; j < fechasCruzadas.length; j++) {
    if (fechasCruzadas[i] === fechasCruzadas[j]) {
      count++
    }
  }
  if (count > max) {
    max = count
    maxId = fechasCruzadas[i]
  }
}

// La fecha que mas se repite es la fecha que mas se cruza con otras fechas
// por lo quu es la fecha que tenemos que eliminar su fila y columna
for (let i = 0; i < nodosArr.length; i++) {
  matrix[maxId][i] = 0
  matrix[i][maxId] = 0
}

console.log(matrix)

// recorremos la matriz de adyacencia
for (let i = 0; i < nodosArr.length; i++) {
  for (let j = 0; j < nodosArr.length; j++) {

    // guardamos las ofertas en variables
    let fecha1 = nodosArr[i]
    let fecha2 = nodosArr[j]

    if (i !== j) {
      // si no se cruzan y la fecha 1 es mayor que la fecha 2
      if (fecha2.fechaSalida < fecha1.fechaLlegada) {
        matrix[i][j] = 0
      }
    }
  }
}

// solo puede haber un valor por cada fila, en caso de que haya
// mas de uno nos vamos a quedar con la fecha menor
let fechasPosibles = []
for (let i = 0; i < nodosArr.length; i++) {
  for (let j = 0; j < nodosArr.length; j++) {
    if (matrix[i][j] !== 0) {
      fechasPosibles.push(j)
    }
  }
  if (fechasPosibles.length > 1) {
    // obtenemos la fecha menor de cada fecha de llegada
    let fechaMenor = nodosArr[fechasPosibles[0]].fechaLlegada
    let fechaMenorId = fechasPosibles[0]
    for (let k = 0; k < fechasPosibles.length; k++) {
      let fechaActual = nodosArr[fechasPosibles[k]].fechaLlegada
      if (fechaActual < fechaMenor) {
        fechaMenor = fechaActual
        fechaMenorId = fechasPosibles[k]
      }
    }
    // dejamos en cero la casilla de la fecha que no es la menor
    for (let k = 0; k < fechasPosibles.length; k++) {
      if (fechasPosibles[k] !== fechaMenorId) {
        matrix[i][fechasPosibles[k]] = 0
      }
    }
  }
  fechasPosibles = []
}

console.log(matrix)

// Guardamos las fechas en un array (usando las coordenadas de la matriz)
let fechasSeleccionadas = []
for (let i = 0; i < nodosArr.length; i++) {
  for (let j = 0; j < nodosArr.length; j++) {
    if (matrix[i][j] !== 0) {
      fechasSeleccionadas.push(i)
      fechasSeleccionadas.push(j)
    }
  }
}

// creamos un set del array para elminar duplicados
let fechasSeleccionadasSet = new Set(fechasSeleccionadas)
// convertimos el set en un array
fechasSeleccionadas = [...fechasSeleccionadasSet]

// creamos un array de objetos con las fechas seleccionadas
let infoFechasSeleccionadas = []
let montoTotal = 0

// recorremos el array de fechas seleccionadas
for (let i = 0; i < fechasSeleccionadas.length; i++) {
  infoFechasSeleccionadas[i] = nodosArr[fechasSeleccionadas[i]]
  montoTotal += nodosArr[fechasSeleccionadas[i]].montoOfrecido
}

console.log(infoFechasSeleccionadas)
console.log("Monto total ganado: " + montoTotal)