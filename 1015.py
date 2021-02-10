import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
aa = []

for i in range(n):
    aa.append((a[i], i))

aa.sort()

b = []

for i in range(n):
    b.append((i, aa[i][1]))

bb = sorted(b, key=lambda x: x[1])

for i in range(n):
    print(bb[i][0], end=" ")
