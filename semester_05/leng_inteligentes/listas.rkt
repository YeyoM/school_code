#lang racket

(define (obtener-cabecera lista)
  (car lista))

(define (obtener-resto lista)
  (cdr lista))

(define (agregar-elemento lista elemento)
  (cons elemento lista))

; Ejemplo de uso de las funciones
(define mi-lista '(1 2 3 4 5))
(displayln "Lista original:")
(displayln mi-lista)
(displayln "Cabecera de la lista:")
(displayln (obtener-cabecera mi-lista))
(displayln "Resto de la lista:")
(displayln (obtener-resto mi-lista))
(displayln "Agregar el elemento 6 a la lista:")
(define mi-lista-modificada (agregar-elemento mi-lista 6))
(displayln mi-lista-modificada)
