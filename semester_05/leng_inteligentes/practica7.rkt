#lang racket

; Declaración de una función para calcular el factorial de un número
(define (factorial n)
  (if (= n 0)
      1
      (* n (factorial (- n 1)))))

; Declaración de una lista de números
(define lista-numeros '(1 2 3 4 5 6 7 8 9 10))

; Uso de una función de orden superior para filtrar los números pares de la lista
(define numeros-pares
  (filter even? lista-numeros))

(displayln (format "Factorial de 5: ~a" (factorial 5)))
(displayln (format "Lista de números pares: ~a" numeros-pares))