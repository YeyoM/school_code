def multiplicacion(a, b):
  return a * b

numero = int(input("Ingrese un numero para generar su tabla: "))
for i in range(1, 11):
  print("%d * %d = %d" % (numero, i, multiplicacion(numero, i)))