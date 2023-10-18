#lang racket
(cons (+ 1 2)(cons (+ 3 4)empty))
(list (+ 1 2)(+ 3 4))
'((+ 1 2)(+ 3 4))

(define (longitud lst)
  (
   match lst
    [
     '() 0
    ]
    [
     (cons x xs)(+ 1(longitud xs))]))