import random

def generate_random_bits(n):
    opciones = ["0", "1"]
    cadenas = []
    cadena = ""
    for i in range(0, n):
        for j in range(0, 10):
            cadena += random.choice(opciones)
        cadenas.append(cadena)
        cadena = ""
    return cadenas

def cruzar_bits(cadenas):
    for i in range(0, len(cadenas)):
        cadena1 = list(cadenas[i])
        subcadenaA = cadena1[0:5]
        print(''.join(subcadenaA))
        subcadenaB = cadena1[5:10]
        print(''.join(subcadenaB))
        cadena2 = list(cadenas[9 - i])
        subcadenaC = cadena2[0:5]
        print(''.join(subcadenaC))
        subcadenaD = cadena2[5:10]
        print(''.join(subcadenaD))
        nuevaCadena1 = subcadenaA + subcadenaD  
        nuevaCadena2 = subcadenaB + subcadenaC 
        print(''.join(nuevaCadena1))
        print(''.join(nuevaCadena2))
        # aqui comparar las nuevas cadenas y quedarnos con una
        cadenas[i] = ''.join(nuevaCadena1)
        cadena1 = ""
        cadena2 = ""
        subcadenaA = ""
        subcadenaB = ""
        subcadenaC = ""
        subcadenaD = ""
    return cadenas

def main():
    cadenasIniciales = generate_random_bits(10)
    print(cadenasIniciales)
    cadenasMutadas = cruzar_bits(cadenasIniciales)
    print(cadenasMutadas)

if __name__ == "__main__":
    main()

