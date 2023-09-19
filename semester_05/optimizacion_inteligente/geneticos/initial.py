import numpy as np

# Aqui agarramos los datos de los modulos y los guardamos en un array
# Es como nuestra base de datos

# Modulo1 => ID del curso/materia
Modulo1 = np.array([
                    ["LC1-1",  "FEC-2",  "CD-3",   "AS-4",   "CB-5"],                       # Semestre 1
                    ["LC3-6",  "ECA-7",  "IA-8",   "AL-9",   "EDP-10", "RB-11"],            # Semestre 3
                    ["OI-12",  "AU-13",  "AID-14", "LI-15",  "BD-17"],                      # Semestre 5
                    ["AU2-18", "DMD-19", "MH-20",  "ESI-21", "PI-22",  "LE-23", "RE1-24"],  # Semestre 7
                    ["TSI-25", "SI1-26", "SW-27",  "PA-28",  "SIS-29", "MD-30"]             # Semestre 9 
                  ])

# Modulo2 => Grupo
Modulo2 = np.array(["1a", "3a", "5a", "7a", "9a"])

# Modulo3 => Dia de inicio del curso
Modulo3 = np.array(["Lunes", "Martes", "Miércoles"])

# Modulo4 => Hora de inicio del curso
Modulo4 = np.array(["7:00", "8:00", "9:00", "10:00", "11:00", "12:00", "13:00"])

# Modulo5 => Dia de fin del curso
Modulo5 = np.array(["Jueves", "Viernes"])

# Modulo6 => Hora de fin del curso
Modulo6 = np.array(["8:00", "9:00", "10:00", "11:00", "12:00", "13:00", "14:00"])

# Modulo7 => Tipo de aula
Modulo7 = np.array(["Aula", "Lab", "Auditorio"])

# Modulo8 => ID del aula
Modulo8 = np.array([
                    ["54 A", "54 C", "54 F", "54 G", "54 H"],       # Aulas
                    ["61 LAB", "203 LAB", "204 LAB"],               # Laboratorios
                    ["1 AUD"]                                       # Auditorios            
                  ])

# Modulo9 => ID del individuo
Modulo9 = 0

# Creamos un array vacio donde se guardaran los individuos
Poblacion = np.array([])

# Aqui generamos los individuos, Agregando a Individuo el valor de cada modulo que generamos aleatoriamente
# @Modulo9 es un contador que nos ayuda a saber cuantos individuos se han generado
# @Choques es una funcion que nos ayuda a saber si el individuo tiene choques de horario
def Generacion():
    global Modulo9
    Individuo = [np.random.choice(Modulo1), np.random.choice(Modulo2), np.random.choice(Modulo3),
                np.random.choice(Modulo4), np.random.choice(Modulo5), np.random.choice(Modulo6),
                np.random.choice(Modulo7), np.random.choice(Modulo8), Modulo9]

    Poblacion.append(Individuo)
    Modulo9 = Modulo9 + 1
    Individuo.append(Choques(Individuo))
    return Individuo

#Aqui se evalua si el individuo tiene choques de horario
#Creamos un contador que nos ayudara a saber cuantos choques de horario tiene el individuo
def Choques(Individuo):
    Choques = 0
    HorarioEntrada = Individuo[3]
    HorarioSalida = Individuo[5]
    if HorarioEntrada > HorarioSalida:
        Choques = Choques + 1
    return Choques


print("Materia  - Grupo  -  Día  -  Hora  -  Día  -  Hora  -  Tipo  -  Aula - No. Individuo")
for i in range(10):
    Generacion()
    print(Poblacion[i])
