# TIPOS DE VALIDACION

x = 1
y = "Hola"

print(x)
print(y)

# OPERADORES NUMERICOS

x = 5
y = 2

print(x + y)
print(x - y)
print(x * y)
print(x / y)
print(x % y)
print(x ** y)

x=0

if x > 0:
    print("hola mundo")


#así se hacen los comentarios que loco

#strings
print("hola mundo")

#integer
print(60)

#float
print(30.5)

#boolean
True
False

#list - A diferencia de tuples este si puede ser modificado
[1, 2, 3, 4]
["hola", " bye", " jeje"]

#tuples - A diferencia de lists este NO puede ser cambiado
(20, 40, 50)

# Dictionaries - Sirve para agrupar datos de una sola entidad
{"nombre":"Abraham",
"apellido":"Muro",
"sexo":"Hombre"}

None # Que no hay nada

# VARIABLES -

msg = "Hello World"
print(msg)

# case sensitive
book = "luna de plutón"
Book = "luna de plutón"

# Guardar variables dentro de una misma linea
hola, amigos = "adios", 1 #Respectivamente

# Conventions
book_name = "The Shining" # Snake case
bookName = "Don Quijote" # Camel Case
BookName = "Hola mundo" # Pascal Case

# Constant
PI = 3.1416

#  ===     S T R I N G S        ===

#Funcionalidades

print(msg.upper()) # Mayúsculas
print(msg.lower()) # Minúsculas

# remplazar
print(msg.replace("Hello", "Hola").upper()) # Remplaza Hello por Hola y lo hace mayúsculas
print(msg.count("l")) # Cuenta la cantidad de caractéres que sean "l"

#empezar
print(msg.startswith('Hello')) # Booleano que menciona si empieza con "hello"
print(msg.endswith("word")) # Caso contrario pero con "word"

#separar y encontrar
print(msg.split('o')) # separa el string por partes donde encuentre una 'o'
print(msg.find('o')) # Regresa valor donde se ENCUENTRA el caracter o cadena

#longitud
print(len(msg)) #Imprime longitud empezando desde 0
print(msg[0])

print(msg[-1])

#operadores de concatenación

print("Mi archivo se llama: " + msg)

# == N Ú M E R O S ==
# Too lo que insertamos al programa es un string por ende

edad = input("Digita tu edad: ")
edad_nueva = int(edad) + 10
print(edad_nueva)
