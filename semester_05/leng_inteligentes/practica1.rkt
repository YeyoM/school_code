#lang racket
(+ 1 2)
(- 1 1/4)
(+ 1 (- 3 4))
(or (< 5 4)(equal? 1 (- 6 5)))
(and (not(zero? 10))(+ 1 2 3))
(string-append "Ho" "la")
(string-length "Hola mundo")
(substring "Apple" 3)

# generar una funcion que calcule el area de un triangulo
(define (area-triangulo base altura)
  (if (or (<= base 0) (<= altura 0))
      (error "Los parametros deben ser positivos")
      (* 1/2 base altura)))