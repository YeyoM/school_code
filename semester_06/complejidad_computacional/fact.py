import big_o


def factorial(n):
    if n == 0:
        return 1
    else:
        return n * factorial(n - 1)


best, others = big_o.big_o(factorial, big_o.datagen.n_, min_n=20, max_n=300)
print(best)
