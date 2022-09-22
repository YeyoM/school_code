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

def mutar_bits(cadenas):
    for i in range(0, len(cadenas)):
        cadena1 = list(cadenas[i])
        cadena2 = list(cadenas[9 - i])
        for j in range(0, len(cadenas[i])):
            opciones = [cadena1[j], cadena2[j]]
            nuevaCadena = random.choice(opciones)
            cadenas[i] = cadenas[i].replace(cadena1[j], nuevaCadena)
    return cadenas

def main():
    cadenasIniciales = generate_random_bits(10)
    print(cadenasIniciales)
    cadenasMutadas = mutar_bits(cadenasIniciales)
    print(cadenasMutadas)

if __name__ == "__main__":
    main()

