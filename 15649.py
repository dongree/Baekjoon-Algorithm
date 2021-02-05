from itertools import permutations
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

a = [i for i in range(1, n+1)]
b = list(permutations(a, m))

for j in range(len(b)):
    for k in range(m):
        print(b[j][k], end=' ')
    print()
