import big_o


def recur4(n, x):
    if n <= 1:
        return 1
    else:
        for _ in range(1, n):
            x = x + 1
        return recur4(n - 1, x)


x = 2
best, others = big_o.big_o(
    lambda n: recur4(n, x), big_o.datagen.n_, min_n=10, max_n=200
)
print(best)
