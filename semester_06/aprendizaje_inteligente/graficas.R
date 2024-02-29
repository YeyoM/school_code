#Graficos en R
# El comando plot()

x <- runif(50,0,4) # 50 numeros que sigen la normal entre 0 y 4
y <- runif(50,0,4) # 50 numeros que sigen la normal entre 0 y 4
plot(x,y, main = "Titulo principal", sub = "subtitulo", xlab = "Etiqueta Eje X", ylab = "Etiqueta Eje Y",
xlim = c(-1,5), ylim = c(1,5), col = "red") # Grafica de dispersion

# Varicaciones de plot

z <- cbind(x,y)
z
plot(z)

plot(log(y + 1) - x)

plot(x, y, type = "p") # Grafica de puntos

plot(x, y, type = "l") # Grafica de lineas

plot(x, y, type = "b") # Grafica de puntos y lineas

plot(c(1,5), c(1,5))
legend(1, 4, c("uno", "dos", "tres"), lty = 1:3, col = c("red", "blue", "green"), pch = 15:17, cex = 2)

#Elementos parecidos a un "plot"
plot(1:10, 1:10, axes = FALSE, xlab = "", ylab = "")
polygon(runif(4, 1, 10), runif(4, 1, 10), col = "lightblue")
points(runif(5, 1, 10), runif(5, 1, 10), cex = 1.5, col = "red")
points(runif(5, 1, 10), runif(5, 1, 10), pch = "+", cex = 1.7, col = "green")
lines(1:10, runif(10, 1, 10), lty = 2, lwd = 2)
text(runif(5, 1, 10), runif(5, 1, 10), labels = c("uno", "dos", "tres", "cuatro", "cinco"), cex = 1.7, col = rainbow(5), abline(h = 5, lty = 2))
axis(2, labels = 1:10, at = 1:10)
legend(8, 3, lty = c(1:3), col = rainbow(3), legend = c("uno", "dos", "tres"))

#Tipos de puntos en un plot con los comandos plot: pch, cex, col 
plot(x, y, type = "n")
points(x, y, pch = 3, col = "red")
plot(c(1, 10), c(1, 3), type = "n", axes = FALSE, xlab = "", ylab = "")
points(1:10, rep(1, 10), pch = 1:10, cex = 2, col = "blue")
points(1:10, rep(2, 10), pch = 11:20, cex = 2, col = "red")
points(1:5, rep(3, 5), pch = 21:25, cex = 2, col = "blue", bg = "yellow")

par(mfrow = c(2, 2))
plot(rnorm((10)))
plot(runif(5), rnorm(5))
plot(runif(10))
plot(rnorm(10), rnorm(10))

#Bar char y dot char

VADeaths

barplot(VADeaths, beside = TRUE, ylim = c(0, 90), ylab = "Muertes por cada 1000", main = "Tasas de Mortalidad en Virginia")

dotchart(VADeaths, xlim = c(0, 75) ,xlab = "Muertes por cada 1000", main = "Tasas de Mortalidad en Virginia")
