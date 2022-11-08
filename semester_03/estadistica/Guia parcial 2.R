#:01 Distribución Binomial (Unico valor)----
dbinom(x=1,size = 2,prob=1/6)

#:02 Distribución Binomial (Suma)----
#Ambas formulas funcionan
sum(dbinom(x=1:49,size=53,prob=0.93))
pbinom(q=49,size=53,prob=0.93)

#:03 Distribucion Geometrica(Unica)----
dgeom(x=124,prob=0.01)

#:04 Distribución Geometrica (Suma)----
pgeom(q=50,prob=0.01)

#:05 Distribucion Binomial Negativa(Unica)----
p <- 0.15
r <- 2
# conjunto de valores posibles
x <- r:15000
x.aux <- x - r # OJO con esta linea
fx <- dnbinom(x = x.aux, size = r, prob = p)
fx[1]

#:06 Distribución Binomial Negativa (Suma)----
sum(dnbinom(x=0:1,size=2,prob=0.5))

#:07 Distribución Poisson (Unica)----
dpois(x=1,lambda = 5.2)

#:08 Distribución Poisson (Suma)----
sum(dpois(x=0:4,lambda = 5.2))

#:09 Función Generadora de Momentos----
f<-expression(p^r*(exp(-t)-1+p)^-r)

t<-0
r<-2
p<-0.15

ff<-D(f,'t')
fff<-D(ff,'t')
ffff<-D(fff,'t')

esperanza<-eval(ff)

esperanza_cuadrado<-eval(fff)

varianza<-esperanza_cuadrado-(esperanza*esperanza)

esperanza

esperanza_cuadrado

varianza