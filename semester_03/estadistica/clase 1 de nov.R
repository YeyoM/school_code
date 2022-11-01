# Práctica: distribuciones de 
#           probabilidad discretas
# rm(list=ls())
# 
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
#    ruleta, n = 10 y p = 18/38 = 0.4737.

# Valores de los parámetros
n<- 20 # 10 # 
p<- 18/38
x<- 0:n    # conjunto de valores posibles
f.x<- choose(n=n,k=x)*p^x*(1-p)^(n-x)
F.x<- cumsum(f.x)
fx<- dbinom(x=x,size=n,prob=p)
Fx<- pbinom(q=x,size=n,prob=p)
mat<- cbind(x,f.x,fx,F.x,Fx)
mat<- round(mat,4)
mat

moda<- which.max(fx)
moda
moda<- x[moda]
moda

media<- n*p
media
media.formula.universal<- sum(x*fx)
media.formula.universal

aux<- which(Fx>=0.5)
mediana<- x[aux[1]]
mediana

varianza<- n*p*(1-p)
varianza.formula.universal<- 
  sum((x-media)^2*fx)
varianza.formula.universal
desviacion.estandar<- sqrt(varianza)


x11()
main<- "función de densidad binomial"
xlab<- "x: número de juegos ganados"
ylab<- "f(x): probabilidad"
plot(x,fx,xlab=xlab,ylab=ylab,main=main,
     type="p",pch=19,col="red")
rug(x,col="blue")
points(c(media,moda),c(0,0),pch=c(3,2),
       col=c("green","orange"))
leyenda<- c("media","moda")
legend(x="topright",legend=leyenda,
       pch=c(3,2),col=c("green","orange"),
       text.col=c("green","orange"))

x11()
main<- "función de distribución binomial"
xlab<- "x: número de juegos ganados"
ylab<- "F(x): probabilidad acumulada"
plot(x,Fx,xlab=xlab,ylab=ylab,main=main,
     type="p",pch=19,col="red")
rug(x,col="blue")
points(c(media,moda,mediana),
       c(0,0,0.05),pch=c(3,2,4),
       col=c("green","orange","yellow"))
leyenda<- c("media","moda","mediana")
legend(x="bottomright",legend=leyenda,
       pch=c(3,2,4),
       col=c("green","orange","yellow"),
       text.col=c("green","orange","yellow"))




# ibarra, torres, ortiz, caldera, 2022-10-10


#:02 Distribución de Poisson -----
#    X~Po(mi)
#    f(x) = P(X=x) = exp(-mi)mi^x/x!
#    para x = 0,1,2,...

# Ejercicio 3.105 del libro de Montgomery
# a)
mi<- 0.5  
x<- 0
f.x<- exp(-mi)*mi^x/factorial(x)
fx<- dpois(x=x,lambda=mi)
c(x,fx,f.x)

# b)
mi<- 5  
x<- 0
f.x<- exp(-mi)*mi^x/factorial(x)
fx<- dpois(x=x,lambda=mi)
c(x,fx,f.x)
# c)
# Z = número de autos con defectos en superficie plástica
# Z~bin(n=10,p=0.3935)
n<- 10
p<- 0.3935
# C = {Z<=1}; a lo más hay 1 defecto
z<- 1  
Fz<- pbinom(q=z,size=10,prob=p)
f.z<- dbinom(x=c(0,1),size=10,prob=p)
F.z<- cumsum(f.z)
c(z,Fz,F.z)

#:03 Distribuciones geométrica y binomial negativa ----------

p<- 0.0005
r<- 3
# conjunto de valores posibles
x<- r:15000  
x.aux<- x-r   # OJO con esta linea

fx<- dnbinom(x=x.aux,size=r,prob=p)
moda<- which.max(fx)
moda<- moda+r

fx[1]   # P(X=3) = f(3)
fx[2]   # P(X=4) = f(4)
fx[3]   # P(X=5) = f(5)


x11()
plot(x,fx,col="red")

# b) Ejercicio 3.83 p.p 83 (106)
# X = tiempo de paro de la linea de producción
#     (hasta que haya 3 costales con bajo peso)
# X ~ binneg(r=3,p=0.001)

r<- 3
p<- 0.001
mi<- r/p               # EX
sigma2<- r*(1-p)/p^2   # VX
sigma<- sqrt(sigma2)   # d.e.(X)
c(mi,sigma2,sigma)

# Obtenga  además la probabilidad del evento {X<9} = {X<=8}
# Tres formas de calcular esta probabilidad

0.001^r*( 
  choose(n=2,k=2)*0.999^0 +choose(n=3,k=2)*0.999^1
  +choose(n=4,k=2)*0.999^2 +choose(n=5,k=2)*0.999^3
  +choose(n=6,k=2)*0.999^4 +choose(n=7,k=2)*0.999^5)

x<- r:8
fx<- choose(n=x-1,k=2)*p^r*(1-p)^(x-r)
sum(fx)

pnbinom(q=8-r,size=r,prob=p)   # OJO con esta linea




#:04 Función generadora de momentos ------
#    Práctica que toma como base Ejercicio 3.115 p.p. 94 (117)

# conjunto de valores posibles
x<- 1:5
fx<- c(0.05,0.1,0.2,0.25,0.4)

x11()
plot(x,fx)

tabla<- cbind(x,fx)
tabla
colSums(tabla)

xfx<- x*fx
x2fx<- x^2*fx
x3fx<- x^3*fx

tabla<- cbind(tabla,xfx,x2fx,x3fx)
tabla
colSums(tabla)




