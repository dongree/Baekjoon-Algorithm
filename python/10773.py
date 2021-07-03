# import sys
# input = sys.stdin.readline
# 이것을 사용하면 시간 단축 가능

k = int(input())

a = []

for _ in range(k):
    b = int(input())
    if (b == 0):
        a.pop()
    else:
        a.append(b)

print(sum(a))
