import numpy as np

# Aqui agarramos los datos de los modulos
import modulos.modulos as modulos
Modulo1 = modulos.Modulo1
Modulo2 = modulos.Modulo2
Modulo3 = modulos.Modulo3
Modulo4 = modulos.Modulo4
Modulo5 = modulos.Modulo5
Modulo6 = modulos.Modulo6
Modulo7 = modulos.Modulo7
Modulo8 = modulos.Modulo8
Modulo9 = modulos.Modulo9

# Importamos la funcion de generacion de individuos
from utils.Generacion import Generacion

def main():
    
    Poblacion = []

    print("Materia  - Grupo  -  Día  -  Hora  -  Día  -  Hora  -  Tipo  -  Aula - No. Individuo")
    for i in range(30):
        Generacion(Modulo1, Modulo2, Modulo3, Modulo4, Modulo5, Modulo6, Modulo7, Modulo8, Modulo9, Poblacion)
        print(Poblacion[i])


if __name__ == "__main__":
    main()