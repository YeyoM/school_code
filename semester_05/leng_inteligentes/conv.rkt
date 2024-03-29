#lang racket

(define (pregunta-inicial)
  (displayln "Hola, ¿cómo estás?")
  (define respuesta (read-line))
  (if (string=? respuesta "Adiós")
      (displayln "¡Hasta luego!")
      (comenzar-conversacion respuesta)))

(define (comenzar-conversacion pregunta)
  (display "Entiendo, ¿puedes explicar más sobre eso? ")
  (define respuesta (read-line))
  (if (string=? respuesta "Adiós")
      (displayln "¡Hasta luego!")
      (comenzar-conversacion respuesta)))

(pregunta-inicial)