import numpy as np

# Aqui agarramos los datos de los modulos y los guardamos en un array
# Es como nuestra base de datos

# Modulo1 => ID del curso/materia
Modulo1_Clases_Sem_1 = np.array(["LC1-1",  "FEC-2",  "CD-3",   "AS-4",   "CB-5"])
Modulo1_Clases_Sem_3 = np.array(["LC3-6",  "ECA-7",  "IA-8",   "AL-9",   "EDP-10", "RB-11"])
Modulo1_Clases_Sem_5 = np.array(["OI-12",  "AU-13",  "AID-14", "LI-15",  "BD-17"])
Modulo1_Clases_Sem_7 = np.array(["AU2-18", "DMD-19", "MH-20",  "ESI-21", "PI-22",  "LE-23", "RE1-24"])
Modulo1_Clases_Sem_9 = np.array(["TSI-25", "SI1-26", "SW-27",  "PA-28",  "SIS-29", "MD-30"])

Modulo1 = [Modulo1_Clases_Sem_1, Modulo1_Clases_Sem_3, Modulo1_Clases_Sem_5, Modulo1_Clases_Sem_7, Modulo1_Clases_Sem_9]

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
Modulo8_Aulas = np.array(["54 A", "54 C", "54 F", "54 G", "54 H"])
Modulo8_Labs  = np.array(["61 LAB", "203 LAB", "204 LAB"])
Modulo8_Audis = np.array(["1 AUD"])

Modulo8 = [Modulo8_Aulas, Modulo8_Labs, Modulo8_Audis]

# Modulo9 => ID del individuo
Modulo9 = 0
