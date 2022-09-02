class Grafo {

  // Definimos el constructor con el numero de vertices
  constructor (numVertices) {
    this.numVertices = numVertices
    // Map que guarda como key el nodo, y como valor los nodos adyacentes a el
    this.listaNodosAdyacente = new Map()
  }

  agregarVertice(vertice) {
    // Le agregamos el nuevo nodo, y con nodos adyacentes un array vacio
    this.listaNodosAdyacente.set(vertice, [])
  }

  agregarArista(inicio, destino) {
    // Obtener de la lista de nodos adyacentes e ingresar en ellos el nodo destino y viceversa ya que no es un grafo dirigido
    this.listaNodosAdyacente.get(inicio).push(destino)
    this.listaNodosAdyacente.get(destino).push(inicio)
  }

  imprimirGrafo() {
    // obtener todos los vertices
    let vertices = this.listaNodosAdyacente.keys()

    for (let i of vertices) {
      // para cada vertice obtenemos el arr de sus adyacentes
      let verticesAdyacentes = this.listaNodosAdyacente.get(i)
      let verticesAdyacentesTotales = ""

      for (let j of verticesAdyacentes) {
        // guardamos los vertices adyacentes en un string
        verticesAdyacentesTotales += j + " "
      }
      
      // mostramos el vertice y sus adyacentes
      console.log(i + "-> " + verticesAdyacentesTotales)

    }
  }
}

let grafoPrueba = new Grafo(6)
let verticesDePrueba = ['A', 'B', 'C', 'D', 'E', 'F']

for (let i = 0; i < verticesDePrueba.length; i++) {
  grafoPrueba.agregarVertice(verticesDePrueba[i])
}

grafoPrueba.agregarArista('A', 'B')
grafoPrueba.agregarArista('A', 'D')
grafoPrueba.agregarArista('A', 'E')
grafoPrueba.agregarArista('B', 'C')
grafoPrueba.agregarArista('D', 'E')
grafoPrueba.agregarArista('E', 'F')
grafoPrueba.agregarArista('E', 'C')
grafoPrueba.agregarArista('C', 'F')

grafoPrueba.imprimirGrafo()