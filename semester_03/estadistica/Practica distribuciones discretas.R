# Práctica: distribuciones de 
#           probabilidad discretas

# Contenido:
#:01 Distribución binomial 

#:01 Distribución binomial ----------
# X: número de éxitos en n ensayos 
#    de Bernoulli
# X = 0,1,...,n
# n >= 1, es el total de ensayos    
# p = P(E), de cada ensayo, 0 <= p <= 1.

# a) Ejemplo: apostar un peso a los 
#    números rojos en el juego de la
#    ruleta, n = 10 y p = 18/38 ~= 0.4737.

# Valores de los parámetros
n <- 10
p <- 18/38
x <- 0:n    # <- conjunto de valores posibles

# funcion de distribucion de probabilidad binomial (forma manual)
# choose es la combinatoria de n, r
f.x <- choose(n = n, k = x) * p^x * (1-p)^(n-x)
# Suma acumulada de las probabilidades
F.x <- cumsum(f.x)

# funcion de distribucion de probabilidad binomial (dbinom)
fx <- dbinom(x = x, size = n, prob = p)
# Suma acumulada de las probabilidades 
Fx <- pbinom(q = x, size = n, prob = p)

# Creamos la matriz
mat <- cbind(x, f.x, fx, F.x, Fx)

# Todos los valores los redondeamos a 4 decimales
mat <- round(mat, 4)

# Mostramos la matriz
mat

# Moda
moda <- which.max(fx) # <- Devuelve el indice de la moda
moda <- x[moda]       # <- Valor de la media x[moda]
moda

# Media
media <- n * p
media

# Media universal
media.formula.universal <- sum(x*fx)
media.formula.universal

# Mediana
mediana <- which(Fx >= 0.5)[1] # El minimo valor posible que sea mayor/igual a 0.5
mediana <- x[mediana]
mediana

# Varianza
varianza <- n * p * (1 - p)
varianza.formula.universal <- sum((x-media)^2*fx)
varianza
varianza.formula.universal

# Desviacion Estándar
d.e <- sqrt(varianza)
d.e

# Graficas

x11()
main <- "Función de densidad binomial"
xlab <- "x: número de juegos ganados"
ylab <- "f(x): probabilidad"

plot(x, fx, xlab = xlab, ylab = ylab, main = main,
     type = "p", pch = 19, col = "red")

rug(x, col = "blue")

points(c(media, moda), c(0, 0), pch = c(3, 2),
       col = c("green", "orange"))

leyenda <- c("media", "moda")

legend(x = "topright", legend = leyenda,
       pch = c(3, 2), col = c("green", "orange"),
       text.col = c("green", "orange"))

x11()
main <- "Función de distribución binomial"
xlab <- "x: número de juegos ganados"
ylab <- "F(x): probabilidad acumulada"

plot(x, Fx, xlab = xlab, ylab = ylab, main = main,
     type = "p", pch = 19, col = "red")

rug(x, col = "blue")

points(c(media, moda, mediana), c(0, 0, 0.09), pch = c(3, 2, 1),
       col = c("green", "orange", "red"))

leyenda <- c("media", "moda", "mediana")

legend(x = "bottomright", legend = leyenda,
       pch = c(3, 2, 1), col = c("green", "orange", "red"),
       text.col = c("green", "orange", "red"))






