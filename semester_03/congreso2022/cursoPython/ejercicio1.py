nombre = input("Ingrese su nombre completo: ")
edad = int(input("Ingrese su edad: "))
caracter = input("Ingrese un caracter: ")

if edad >= 18:
  print("Hola %s, usted es mayor de edad" % nombre)
else:
  print("Hola %s, usted es menor de edad" % nombre)

cuenta = 0

for i in nombre:
  if i.lower() == caracter.lower():
    cuenta += 1

print("El caracter %s aparece %i veces en su nombre" % (caracter, cuenta))
