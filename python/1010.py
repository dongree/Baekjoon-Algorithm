t = int(input())

for _ in range(t):
    a, b = map(int, input().split())
    c = 1
    d = 1
    for i in range(b, b-a, -1):
        c *= i
    for j in range(1, a+1):
        d *= j

    print(int(c/d))
