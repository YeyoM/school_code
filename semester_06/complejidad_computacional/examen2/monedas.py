"""
Dado el problema del cambio de monedas, resolver por 3 diferentes métodos:
    1. Divide y vencerás
    2. Greedy (voraz)
    3. Programación dinámica

El problema de la moneda es el siguiente...

Dada una cantidad de dinero, se desea encontrar la menor cantidad de monedas 
de un determinado valor que sumen esa cantidad. Por ejemplo, si se tiene 
disponible monedas de 1, 2 y 5, y se desea obtener la cantidad de 8, se 
necesitarían 3 monedas (5, 2 y 1).

Se supone que se tiene una cantidad infinita de monedas de cada denominación. 
"""

from math import ceil, floor


# Algoritmo para el método de divide y vencerás
def monedas_divide_y_venceras(cantidad, monedas):
    # Un caso base, seria si la cantidad esta dentro de las monedas
    if cantidad in monedas:
        return {cantidad: 1}
    # en caso contrario, se divide la cantidad en dos y se llama recursivamente
    # una mitad con cant / 2 (floor) y la otra con cant / 2 (ceil)
    else:
        left_half = monedas_divide_y_venceras(floor(cantidad / 2), monedas)
        right_half = monedas_divide_y_venceras(ceil(cantidad / 2), monedas)
        # se suman los resultados de las dos mitades para que quede en un solo diccionario
        return {
            k: left_half.get(k, 0) + right_half.get(k, 0)
            for k in set(left_half) | set(right_half)
        }


# Algoritmo para el método Greedy
def monedas_greedy(cantidad, monedas):
    monedas_necesarias = {}
    # Se ordenan las monedas de mayor a menor
    monedas = sorted(monedas, reverse=True)
    # Se recorren las monedas
    for moneda in monedas:
        # Se calcula la cantidad de monedas necesarias
        monedas_necesarias[moneda] = cantidad // moneda
        # Se actualiza la cantidad
        cantidad = cantidad % moneda
    return monedas_necesarias


# Algoritmo para el método de programación dinámica
def monedas_programacion_dinamica(cantidad, monedas):
    memo = [0] + [float("inf")] * cantidad

    for i in range(1, len(memo)):
        for j in range(len(monedas)):
            if monedas[j] <= i:
                sub_res = memo[i - monedas[j]]
                if sub_res != float("inf") and sub_res + 1 < memo[i]:
                    memo[i] = sub_res + 1

    return memo[cantidad]


# Main
if __name__ == "__main__":
    # Monedas
    monedas = set([1, 2, 5])
    # Se define la cantidad de dinero a obtener
    cantidad = 9

    # Divide y vencerás
    print("Divide y vencerás")
    print(monedas_divide_y_venceras(cantidad, monedas))
    # Big O
    # runtime: O(2^n)
    # space: O(1)

    # Greedy
    print("Greedy")
    print(monedas_greedy(cantidad, monedas))
    # Big O
    # runtime: O(n)
    # space: O(1)

    # Programación dinámica
    monedas = [1, 2, 5]
    print("Programación dinámica")
    print(monedas_programacion_dinamica(cantidad, monedas), "monedas")
    # Big O
    # runtime: O(n*m)
    # space: O(n+m)
