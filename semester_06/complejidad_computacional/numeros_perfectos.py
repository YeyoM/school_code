# Diego Moreno, ICI 6to

# Preguntas:
# 1. Funciona, pero cuando ingreso 5 no ha terminado de correr
# 2. Para el quinto tarda demasiado, no ha terminado de correr
# 3. Big O, a priori deberia de ser O(n^2), el problema es que n
#    no es el input, sino el numero primo en si, ejemplo:
#    input 1, n = 6
#    input 2, n = 28
#    input 3, n = 496
#    input 4, n = 8128

# Pedir al usuario la cantidad de numeros perfectos que desea calcular
# y mostrarlos en pantalla.

# Ejemplo
# Input: 3
# Output: 6, 28, 496

# Un numero perfecto es aquel que es igual a la suma de sus divisores
# propios (excluyendo el mismo).

# 6 = 1 + 2 + 3
# 28 = 1 + 2 + 4 + 7 + 14


# Funcion para calcular los divisores de un numero
def divisores(num):  # -> O(n)
    divisores = []
    for i in range(1, num):
        if num % i == 0:
            divisores.append(i)
    return divisores


# Funcion para calcular si un numero es perfecto
def es_perfecto(num):  # -> O(nd) == O(n), d = divisores
    suma = sum(divisores(num))
    if suma == num:
        return True
    else:
        return False


# Funcion principal
def __main__():
    print("Ingrese la cantidad de numeros perfectos que desea calcular")
    cantidad = int(input())
    numeros_perfectos = []
    i = 1
    # Este loop se ejecuta hasta que encunetre los n
    # numeros primos
    # n = 1, -> 6
    # n = 2, -> 28
    # n = 3, -> 496
    # n = 4, -> 8128
    # n = 5, -> 33550336
    # ...
    while len(numeros_perfectos) < cantidad:
        if es_perfecto(i):
            numeros_perfectos.append(i)
        i += 1
    print(numeros_perfectos)


__main__()
