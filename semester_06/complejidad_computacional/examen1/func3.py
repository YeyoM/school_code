import big_o


def recur3(n):
    if n <= 1:
        return 1
    else:
        return 2 * recur3(n / 2)


print(big_o.big_o(recur3, big_o.datagen.n_, n_repeats=10, min_n=2, max_n=20)[0])
