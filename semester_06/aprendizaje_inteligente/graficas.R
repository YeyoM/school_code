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
