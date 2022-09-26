# PRÁCTICA: 
# Estadísticas descriptivas
# 
# Contenido:
#:01 Estadísticas descriptivas
#:02 Histograma
#:03 Diagrama de caja y brazos
#:04 Gráfrica de pasteles

#:01 Estadísticas descriptivas ------------------------------------------------

# Población objetivo: 
# estudiantes universitarios de la UAA
# La variable aleatoria de interés es
# X: suma en pesos de monedas en bolsillos
# 
# Elimina todos los elementos de R 
# en la memoria
# rm(list=ls())

# Muestra de tamaño
# n = 42
# La muestra aleatoria se construye con
# la función "c()", que crea un vector 

# Ejemplo de muestra sesgada a la derecha
x<- c(-1,1,4)  
# Ejemplo de muestra simétrica respecto de su media muestral
x<- c(-1,1,3)  
# Ejemplo de muestra sesgada a la izquierda
x<- c(-1,1,2)  
x<- c(1,-1,-4)  

# Muestra de datos reales
x<- c( 2, 2,17,38,13,13,13, 0, 0, 0,
       0, 0, 0, 0,31,24,25,15,15,15,
       8, 7, 7,20, 5,10,10, 6, 6,42,
       100, 3, 3,20, 4,22,93,50,50,43,
       15,20)

x

n<- length(x)  # tamaño de muestra
n

# La media muestral es el centro de
# la muestra
media<- mean(x)
media  # escala de medición en pesos

# La varianza muestral mide la 
# dispersión de la muestra (incertidumbre,
# volatilidad, impresición, riesgo, 
# o tolerancia de medición)
# Hay dos versiones: sesgada e insesgada
# varianza insesgada (no tiene sesgo)
varianza<- var(x)  # divide entre n-1
varianza

# varianza sesgada (tiene sesgo)
varianza.sesgada<- varianza*(n-1)/n
varianza.sesgada


# La desviación estándar mide la 
# dispersión de la muestra, en la escala 
# original
d.e. <- sqrt(varianza)
d.e.sesgada <- sqrt(varianza.sesgada)
d.e.
d.e.sesgada

estadisticas.descriptivas<-
  c(n,media,varianza,varianza.sesgada,
    d.e.,d.e.sesgada)
estadisticas.descriptivas

nombre.e.d.<- c("tam. muestra","media",
                "var","var.sesgada",
                "d.e.","d.e.sesgada")
nombre.e.d.
names(estadisticas.descriptivas)<-
  nombre.e.d.
estadisticas.descriptivas

# muestra estandarizada
z<- (x-media)/d.e.sesgada
z

x11()     # ventana aparte
hist(z)

# La muestra estandarizada tiene media muestral 
# cero y varianza muestral sesgada uno.
mean(z)         # debe ser cero
var(z)          # es ligeramente mayor que uno
var(z)*(n-1)/n  # debe ser uno


# Coeficientes de sesgo y curtosis.
# En poblaciones "normales",
# el sesgo es 0.0 mientras que la
# curtosis es 3.0. Una curtosis mayor que 3 indica
# que una o ambas colas de la distribución es
# más pesada que lo "normal".

sesgo<- mean(z^3)
curtosis<- mean(z^4)
sesgo    
curtosis

# En el ejemplo de la muestra con la
# variable aleatoria cantidad de 
# monedas en pesos, se obtiene:
# sesgo = 2.1552
# curtosis = 7.8039.
# Por lo tanto la muestra tiene un sesgo
# positivo (a la derecha) y su cola derecha 
# es pesada.

# Cuantiles

cuartiles<- quantile(x)
deciles<- quantile(x,probs=seq(0,1,by=0.1))
cbind(1:n,sort(x))
cbind(1:11,deciles)


#:02 Histograma ---------------------------------------------------------------

x11()     # ventana aparte
hist(x)

x11()     # ventana aparte
hist(x,
     main = "histograma de pesos en bolsillos",
     xlab = "pesos",ylab="frecuencia",
     col = "pink")

x11()     # ventana aparte
main<- "histograma de pesos en bolsillos"
xlab<- "pesos"
ylab<- "frecuencia"
breaks<- 10  # número 'aproximado' de intervalos de clase
hist<- hist(x,breaks=breaks,main=main,xlab=xlab,
            ylab=ylab,col="pink")
rug(x,col="blue")

# límites de intervalos de clase
lic<- hist$breaks
frecuencias.absolutas<- hist$counts
tabla.de.frecuencias<-
  cbind(lic[-length(lic)],lic[-1],frecuencias.absolutas)
tabla.de.frecuencias
colnames(tabla.de.frecuencias)<-
  c("límite inferior","límite superior","frecuencia")
tabla.de.frecuencias

# Construcción de los intervalos de clase
LIC<- c(0,30,60,90,120)
x11()     # ventana aparte
main<- "histograma de pesos en bolsillos"
xlab<- "pesos"
ylab<- "frecuencia"
hist<- hist(x,breaks=LIC,main=main,xlab=xlab,
            ylab=ylab,col="pink")
plot(hist,ylim=c(-10,50))
rug(x,col="blue")

#:03 Diagrama caja y brazos ----------------------------------------------------

x11()     # ventana aparte
caja<- boxplot(x,horizontal=T)
# axis(side=1,at=1:100,labels=F)
# rug(x,col="blue")


# Diagrama de caja y brazos con categorías

sexo<- rep(c(0,1),21)
sexo

sexo<- c(rep(1,15),rep(0,27))
sexo
cbind(sexo,x)


# variable sexo tipo caracter
# sexo.carac<- rep(NA,n)
# sexo.carac
# sexo.carac<- ifelse(sexo==1,"mujer","hombre")
# sexo.carac

plot(sexo,x)
plot(sexo,x,xaxt='n')  # Elimina escala de eje horizontal
axis(side=1,at=c(0,1),labels=c("hombre","mujer"))

etiqueta<- c("hombre","mujer")
boxplot(x~sexo,xaxt='n',col=c("lightblue","yellow"))
axis(side=1,at=c(1,2),labels=etiqueta)


#:04 Función de distribución empírica -----------------
# Su representación gráfica es la gráfica de puntos
# (xi,i/n); para i=1,2,...,n
# Los datos de'x' están ordenados

x.ord<- sort(x)
x.ord

x.ord<- sort(x,index.return=TRUE)
x.ord

# OJO: no intercambiar las siguientes dos lineas
orden<- x.ord$ix
x.ord<- x.ord$x
x.ord
Fn.x<- (1:n)/n

cbind(x,sexo,orden,x.ord,sexo[orden])

x11()
xlab<- "pesos en moneda en bolso" 
ylab<- "Fn(x)"
main<- "funcón de distribución empírica"

plot(x.ord,Fn.x,xlab=xlab,ylab=ylab,
     main=main)

color<- c("green","red")
pch<- c(1,2)               # tipo de punto

col.aux<- pch.aux<- rep(NA,n)
col.aux<- ifelse(sexo==1,color[1],color[2])
pch.aux<- ifelse(sexo==1,pch[1],pch[2])
col.aux<- col.aux[orden]
pch.aux<- pch.aux[orden]
cbind(sexo[orden],col.aux,pch.aux)

plot(x.ord,Fn.x,xlab=xlab,ylab=ylab,
     main=main,col=col.aux,pch=pch.aux)
titulo<- "sexo"
leyenda<- c("mujer","hombre")
legend(x="bottomright",legend=leyenda,
       title=titulo,pch=pch,col=color,
       text.col=color,title.col="black")


#:05 Gráfrica de pastel (pie) ------------------

sexo.porcentaje<- c(15,27)/(15+27)
pie(sexo.porcentaje)