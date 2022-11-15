# Practica de distribuciones continuas

# 01 Distribución normal estándar

p2 <- pnorm(q = 2)
p1 <- pnorm(q = -2)
aux <- c(p1, p2, p2 - p1)
round(aux, 4)

p2 <- pnorm(q=1.96)
p1 <- pnorm(q=-1.96)
aux <- c(p1, p2, p2-p1)
round(aux, 4)

qnorm(0.975)
qnorm(0.5)
qnorm(0.025)
