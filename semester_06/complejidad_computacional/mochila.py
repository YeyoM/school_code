"""
Dada una mochila que puede soportar n kilogramos, y una lista de n
elementos, cada uno con un peso y un valor, se desea determinar la 
combinación de elementos que maximice el valor total de la mochila 
sin exceder el peso máximo.
"""


def mochila(peso_max, elementos):
    """
    Para este problema, se puede ordenar la lista de elementos de
    acuerdo a su valor/peso, y luego seleccionar los elementos
    de mayor valor/peso hasta que se exceda el peso máximo.
    Si se excede el peso máximo, intentamos eliminar el ultimo
    elemento en la mochila y agregar el siguiente elemento en la
    lista de elementos, y repetimos el proceso.
    """
    # elementos[i] = (valor, peso)
    elementos.sort(key=lambda x: x[0] / x[1], reverse=True)
    valor_total = 0
    peso_total = 0
    mochila = []
    for i in range(len(elementos)):
        if peso_total + elementos[i][1] <= peso_max:
            mochila.append(elementos[i])
            valor_total += elementos[i][0]
            peso_total += elementos[i][1]
        else:
            break
    return mochila, valor_total, peso_total


peso_max = 15
elementos = [(4, 12), (2, 1), (10, 4), (1, 1), (2, 2)]

print(mochila(peso_max, elementos))
