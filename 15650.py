# permutation 풀이
# from itertools import permutations
# import sys
# input = sys.stdin.readline

# n, m = map(int, input().split())

# a = [i for i in range(1, n+1)]
# b = list(permutations(a, m))

# for j in b:
#     count = 0
#     for k in range(m-1):
#         if j[k] < j[k+1]:
#             count += 1
#     if (count == m-1):
#         print(' '.join(map(str, j)))

# combination 풀이
from itertools import combinations
import sys
input = sys.stdin.readline

n, m = map(int, input().split())

a = [i for i in range(1, n+1)]
b = list(combinations(a, m))

for j in b:
    print(' '.join(map(str, j)))
