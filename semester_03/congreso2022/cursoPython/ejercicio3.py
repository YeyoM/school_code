import random

def saludo(nombre):
  print("Hola " + nombre)

def generarAleatorio(tope):
  return random.randint(1, tope)

nombre = input("Ingrese su nombre: ")
saludo(nombre)

numero = int(input("Ingrese un numero: "))
aleatorio = generarAleatorio(numero)

print("Tienes 6 intentos para adivinar el numero aleatorio entre 1 y %d" % numero)

for i in range(0, 6):
  numero = int(input("Ingrese un numero: "))
  if numero == aleatorio:
    print("Ganaste!")
    break
  elif numero < aleatorio:
    print("El numero es mayor")
  elif numero > aleatorio:
    print("El numero es menor")
  else:
    print("Perdiste!, el numero era %d" % aleatorio)