# Funcion que calcula el n-esimo numero de la serie de Fibonacci
# En este caso intentaremos calcular hasta el termino 21
# de manera recursiva, y calcularemos la complejidad


def fib(n):
    if n <= 1:
        return n
    return fib(n - 1) + fib(n - 2)


# Calculamos la complejidad

"""
La razón de esta complejidad es que, en cada llamada recursiva,
la función se divide en dos subproblemas, y cada uno de esos 
subproblemas a su vez se divide en dos subproblemas, y así 
sucesivamente. Esto resulta en una cantidad exponencial de 
llamadas a la función, lo que hace que el tiempo de ejecución 
crezca rápidamente a medida que aumenta el valor de "n".
"""

# Probamos la función
print(fib(21))
