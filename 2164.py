from collections import deque

n = int(input())

a = deque()

for i in range(1, n+1):
    a.append(i)

while (len(a) != 1):
    a.popleft()
    b = a.popleft()
    a.append(b)

print(a[0])
