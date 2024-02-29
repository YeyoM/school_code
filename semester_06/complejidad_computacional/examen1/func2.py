import big_o


def recur2(n):
    if n <= 1:
        return 1
    else:
        return 2 * recur2(n - 1)


print(big_o.big_o(recur2, big_o.datagen.n_, n_repeats=10, min_n=2, max_n=20)[0])
