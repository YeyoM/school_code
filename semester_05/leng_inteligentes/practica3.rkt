#lang racket
(define (identidad n)
  (if (string? n)
      (if (equal? "Hola" (substring n 0 4))
          "Hola, como estas"
          "Perdon?")
      "No entiendo"))