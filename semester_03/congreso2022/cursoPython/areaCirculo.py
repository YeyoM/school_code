def areaCirculo (raio):
  return 3.14159 * raio ** 2

def volumeCilindro (raio, altura):
  return areaCirculo(raio) * altura

radio = float(input("Introduce el radio del cilindro (cm): "))
altura = float(input("Introduce la altura del cilindro (cm): "))
print("El volumen del cilindro es: ", volumeCilindro(radio, altura), "cm3")