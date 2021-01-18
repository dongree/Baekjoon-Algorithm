while True:
    n = int(input())
    if n == 0:
        break

    a = []
    for _ in range(n):
        b = input()
        a.append((b.lower(), b))

    a.sort()

    print(a[0][1])
