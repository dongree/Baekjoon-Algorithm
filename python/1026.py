import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

result = 0

while(len(b) != 0):
    result += max(b)*min(a)
    a.pop(a.index(min(a)))
    b.pop(b.index(max(b)))

print(result)
