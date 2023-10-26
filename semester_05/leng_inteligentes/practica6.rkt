#lang racket

(define (comparar-numeros x y)
  (if (< x y)
      (displayln "x es menor que y")
  (if (> x y)
      (displayln "x es mayor que y")
      (displayln "x es igual a y")))

(comparar-numeros 5 10)