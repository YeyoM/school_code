def CalcularHoras(hora_inicio, dia_inicio, hora_fin, dia_fin):
    
    dias = ["Lunes", "Martes", "Miércoles", "Jueves", "Viernes"]

    # Calculamos primero la diferencia de dias
    diferencia_dias = dias.index(dia_fin) - dias.index(dia_inicio) + 1

    # Calculamos la diferencia de horas
    if len(hora_inicio) == 4:
        hora_inicio = hora_inicio[0]
    else:
        hora_inicio = hora_inicio[0:2]

    if len(hora_fin) == 4:
        hora_fin = hora_fin[0]
    else:
        hora_fin = hora_fin[0:2]

    diferencia_horas = int(hora_fin) - int(hora_inicio)

    return diferencia_horas * diferencia_dias