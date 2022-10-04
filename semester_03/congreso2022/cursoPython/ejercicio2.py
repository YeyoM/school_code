# Dada una frase, crear su acronimo
frase = input("Ingrese una frase: ")
frase = frase.upper()

acronimo = []

palabras = frase.split(" ")

for palabra in palabras:
  acronimo.append(palabra[0])

acronimo = "".join(acronimo)

print(acronimo)