import sys
input = sys.stdin.readline

n, k = map(int, input().split())

circle = [i for i in range(1, n+1)]
josephus = []

a = 0

while(len(circle) != 0):
    a = (a+k-1) % len(circle)
    josephus.append(circle.pop(a))

print('<', ', '.join(map(str, josephus)), '>', sep='')
