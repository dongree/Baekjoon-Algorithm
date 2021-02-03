import sys
from collections import deque
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    importance = list(map(int, input().split()))
    printerQueue = deque()
    storage = [(-1, -1)]
    for i in range(n):
        printerQueue.append((importance[i], i))
    while(storage[-1][1] != m):
        if max(printerQueue)[0] > printerQueue[0][0]:
            pop = printerQueue.popleft()
            printerQueue.append(pop)
        else:
            pop = printerQueue.popleft()
            storage.append(pop)
    print(len(storage)-1)
