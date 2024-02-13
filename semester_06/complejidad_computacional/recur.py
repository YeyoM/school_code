def f(n):
    x = 0
    if n <= 1:
        return 1
    else:
        for _ in range(0, n):
            x = 1
            while x < n:
                x = x * 2
        print("n:", n)
        print("dos llamadas")
        return f(n // 2) + f(n // 2)


print(f(10))
