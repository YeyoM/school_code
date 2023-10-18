#lang racket

(define (absoluto n)
  (if (< n 0)
      (* n -1)
      n ))
(define (mes n)
  (cond
    [(= n 1)(display "caso 1")"Enero"]
    [(= n 2)(display "caso 2")"Febrero"]
    [(= n 3)(display "caso 3")"Marzo"]
    [(= n 4)(display "caso 4")"Abril"]
    [(= n 5)(display "caso 5")"Mayo"]
    [(= n 6)(display "caso 6")"Junio"]
    [(= n 7)(display "caso 7")"Julio"]
    [(= n 8)(display "caso 8")"Agosto"]
    [(= n 9)(display "caso 9")"Septiembre"]
    [(= n 10)(display "caso 10")"Octubre"]
    [(= n 11)(display "caso 11")"Noviembre"]
    [(= n 12)(display "caso 12")"Diciembre"]
    [else (error mes "Numero invalido")]
    ))