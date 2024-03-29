class Elemento:
    def __init__(self, ganancia, peso):
        self.ganancia = ganancia
        self.peso = peso


def generarSolucion(maxPeso, arr):
    # Ordenando el arreglo de Elementos por su relacion ganancia/peso
    arr.sort(key=lambda x: (x.ganancia / x.peso), reverse=True)

    # Resultado final (ganancia total)
    resultado = 0.0

    for elemento in arr:
        # Si el peso del elemento es menor o igual al peso maximo
        # se añade la ganancia del elemento al resultado
        if elemento.peso <= maxPeso:
            maxPeso -= elemento.peso
            resultado += elemento.ganancia

    return resultado


if __name__ == "__main__":
    maxPeso = 10
    arr = [Elemento(10, 5), Elemento(7, 3), Elemento(15, 8)]

    resultado = generarSolucion(maxPeso, arr)
    print(resultado)
