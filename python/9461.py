import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    p = [0, 1, 1, 1, 2, 2]
    n = int(input())
    for i in range(5, n):
        p.append(p[i]+p[i-4])
    print(p[n])
