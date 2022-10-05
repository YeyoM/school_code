import random

def checkMonedas(monedas, monedasApostadas):
  if monedasApostadas > monedas:
    print("No tienes suficientes monedas para apostar esa cantidad")
    return False
  else:
    return True

def checkDados(numero):
  if numero < 1 or numero > 6:
    print("Elige un numero entre 1 y 6")
    return False
  else:
    return True

def tirarDado():
  return random.randint(1,6)

def main():

  monedas = 15
  seguir = True

  print("Bienvenido al casion Casino!")
  print("Tienes 15 monedas para apostar en el juego del dado")

  while seguir:

    cantidadApostar = int(input("Cuántas monedas quieres apostar? "))
    if not checkMonedas(monedas, cantidadApostar):
      continue

    numeroApostar = int(input("Elige un numero entre 1 y 6 para apostar: "))
    if not checkDados(numeroApostar):
      continue

    monedas -= cantidadApostar

    dado = tirarDado()
    print("El dado ha sacado un", dado)

    if dado == numeroApostar:
      monedas += cantidadApostar * 3
      print("Has ganado", cantidadApostar, "monedas!")

    else:
      print("Has perdido", cantidadApostar, "monedas")

    print("Tienes", monedas, "monedas")

    if monedas == 0:
      print("Has perdido todas tus monedas")
      break

    seguir = input("Quieres seguir jugando? (s/n) ")
    if seguir == "n":
      print("Gracias por jugar!")
      break

main() 