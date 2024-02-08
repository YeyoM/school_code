import big_o

# La notacion asintotica es una forma de describir el comportamiento de una funcion
# en terminos de la relacion entre su crecimiento y el de otra funcion.

# Notacion Big O
# f(n) = O(g(n)) si y solo si existen constantes c y n0 tales que
# 0 <= f(n) <= c*g(n) para todo n >= n0

# Notacion Omega
# f(n) = Omega(g(n)) si y solo si existen constantes c y n0 tales que
# 0 <= c*g(n) <= f(n) para todo n >= n0

# Notacion Theta
# f(n) = Theta(g(n)) si y solo si f(n) = O(g(n)) y f(n) = Omega(g(n))


# Tomemos la siguiente funcion como ejemplo
def sumatoria(n):
    suma = 0
    for i in range(1, n + 1):
        suma += i
    return suma


# La funcion sumatoria(n) es O(n) ya que el numero de operaciones que realiza
# es proporcional al valor de n. Es decir, si n es el doble, la cantidad de
# operaciones tambien sera el doble.

# Utilizamos la libreria big_o para medir el tiempo de ejecucion de la funcion
# sumatoria(n) con respecto a n

generador = lambda n: big_o.datagen.n_(n)
mejores, otros = big_o.big_o(sumatoria, generador, n_repeats=100)
print(mejores)

# La salida del programa se ve algo asi:
# Linear: time = 0.0072 + 4.1E-06*n (sec)

# La notacion big O de la funcion sumatoria(n) es O(n) ya que el tiempo de
# ejecucion es proporcional a n. La funcion es lineal.
