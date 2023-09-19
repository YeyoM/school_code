# ARTICULOS RELACIONADOS
https://taytzehao.medium.com/classroom-scheduling-using-heuristics-and-genetic-algorithm-b7279ecdd74c
https://github.com/mcychan/GASchedule.py
https://www.codeproject.com/Articles/23111/Making-a-Class-Schedule-Using-a-Genetic-Algorithm

# Cuando podemos tener un choque?

1. Dos clases diferentes en el mismo salon a la misma hora (afecta al horario del salon)
2. Una misma clase a la misma hora en salones diferentes (afecta al horario del grupo)

# Como calcular choques?

Recordar que existen dos entidades que poseen horarios (schedules)

1. Los grupos
2. Los salones

Podemos crear una matriz o un hashmap para cada grupo y para cada salon que represente su horario para que de esta forma para cada nuevo individuo podamos ir calculando los choques

# Como se conforma un individuo?

Un individuo se conforma por 10 modulos

* Modulo 1. Id de cada curso (clase)
* Modulo 2. Grado y grupo que asistira a esa clase. *Nota: un grupo ej. 1A, no puede tomar una clase de utlimo semestre*
* Modulo 3. Primer dia de la semana del curso
* Modulo 4. Hora de inicio del curso
* Modulo 5. Ultimo dia de la semana del curso 
* Modulo 6. Hora de fin del curso
* Modulo 7. Tipo de Aula
* Modulo 8. Id del salon
* Modulo 9. Numero de cromosomas del individuo
* Modulo 10. Numero de choques





