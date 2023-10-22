# Genere un código en Prolog sobre animales (características, tipo de alimentación, etc.), que tenga al menos 2 niveles y al menos 3 reglas por nivel.

# Hagamos una cadena de alimentación de animales, donde cada animal se alimenta del animal que le precede en la cadena.

# Ejemplo:
# El águila se alimenta de la serpiente.
# La serpiente se alimenta del ratón.
# El ratón se alimenta de la hierba.

animal(aguila).
animal(serpiente).
animal(raton).
animal(hierba). # La hierba no se alimenta de nada. y no es animal pero para usos practicos si lo es :)

seAlimentaDe(aguila, serpiente). 
seAlimentaDe(serpiente, raton). 
seAlimentaDe(raton, hierba).  

# Pongamos otro ejemplo:
# El león se alimenta de la cebra.
# La cebra se alimenta de la hierba.

animal(leon).
animal(cebra).

seAlimentaDe(leon, cebra).

# Escribamos una regla que nos diga si un animal es presa de otro.
esPresaElPrimeroDelSegundo(Primero,Segundo):-seAlimentaDe(Segundo,Primero).

# Escribamos una regla que nos diga si un animal es depredador de otro.
esDepredadorElPrimeroDelSegundo(Primero,Segundo):-seAlimentaDe(Primero, Segundo).

# Escribamos una regla que nos diga si un animal es depredador del depredador de otro.
esDepredadorDelDepredadorElPrimeroDelSegundo(Primero,Segundo):-seAlimentaDe(Primero, Tercero), seAlimentaDe(Tercero, Segundo).

# Escribamos una regla que nos diga si un animal es depredador de cualquier otro.
esDepredadorDeCualquierOtro(Primero):-seAlimentaDe(Primero, _).

# Escribamos una regla que nos diga si un animal es presa de cualquier otro.
esPresaDeCualquierOtro(Primero):-seAlimentaDe(_, Primero).