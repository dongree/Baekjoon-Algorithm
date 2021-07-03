
n = int(input())

if n >= 5:
    if (n % 5) % 2 == 0:
        print(n // 5 + (n % 5) // 2)
    else:
        print((n-5) // 5 + (n % 5+5)//2)
else:
    if n % 2 == 0:
        print(n//2)
    else:
        print(-1)
