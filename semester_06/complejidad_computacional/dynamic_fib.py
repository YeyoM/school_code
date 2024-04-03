"""
Siguiendo un enfoque recursivo, como se ha analizado anteriormente,
la función fib(n) se puede definir como la suma de las dos funciones
anteriores, fib(n-1) y fib(n-2), con un caso base para n = 0 y n = 1.

Esto como ya se explicó, es una solución ineficiente, ya que se 
calculan los mismos valores varias veces. 

Para evitar este problema, se puede utilizar un enfoque de programación 
dinámica, donde los valores ya calculados se almacenan en una lista 
para su uso posterior.

Para este caso, utilizaremos la técnica de memorización, la cual
consiste en almacenar los valores de la función en una lista y
utilizarlos en caso de que se vuelvan a necesitar.
"""


def dynamic_fib(n):
    fib = [0, 1]
    for i in range(2, n + 1):
        fib.append(fib[i - 1] + fib[i - 2])
    return fib[n]


print(dynamic_fib(10))  # 55
print(dynamic_fib(50))  # 12586269025
