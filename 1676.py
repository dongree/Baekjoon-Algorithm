import sys
input = sys.stdin.readline

n = int(input())


def factorial(n):
    if n > 1:
        return n * factorial(n-1)
    else:
        return 1


a = factorial(n)

count = 0
while(a % 10 == 0):
    count += 1
    a = a//10

print(count)


# 다른 풀이
# n = int(input())
# print(n//5 + n//25 + n//125)
