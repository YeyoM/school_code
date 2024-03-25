#lang racket

(define (factorial n)
  (if (<= n 1)
      1
      (* n (factorial (- n 1)))))

(define (suma-numeros-enteros n)
  (if (= n 1)
      1
      (+ n (suma-numeros-enteros (- n 1)))))

(displayln "Factorial de 5: ")
(displayln (factorial 5))

(displayln "Suma de los primeros 5 números enteros: ")
(displayln (suma-numeros-enteros 5))