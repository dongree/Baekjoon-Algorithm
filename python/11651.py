n = int(input())

a = []
for _ in range(n):
    x, y = map(int, input().split())
    a.append((x, y))

a = sorted(a, key=lambda x: (x[1], x[0]))

for i in a:
    print(i[0], i[1])


#  조금 더 빠른 풀이
#  sys.stdin.readline이 그냥 input()보다 더 빠르다!
# import sys
# input = sys.stdin.readline

# n = int(input())

# a = []
# for _ in range(n):
#     x, y = map(int, input().split())
#     a.append((x, y))

# a = sorted(a, key=lambda x: (x[1], x[0]))

# for i in a:
#     print(i[0], i[1])
