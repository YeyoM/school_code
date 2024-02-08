# func que imprime los numeros del 1 al 10
def func(n):
    print(n)
    if n < 10:
        func(n + 1)


# func que imprime los numeros del 10 al 1
def func_(n):
    if n < 10:
        func_(n + 1)
    print(n)


print("Primero: ")
func(1)
print("Segundo: ")
func_(1)
