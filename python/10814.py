n = int(input())

a = []

for _ in range(n):
    age, name = input().split()
    a.append((int(age), name))

a = sorted(a, key=lambda x: x[0])

for i in range(n):
    for j in range(2):
        print(a[i][j], end=' ')
    print()
