n = int(input())

a = []
for _ in range(n):
    x, y = map(int, input().split())
    a.append((x, y))

a = sorted(a, key=lambda x: (x[0], x[1]))

for i in a:
    print(i[0], i[1])
