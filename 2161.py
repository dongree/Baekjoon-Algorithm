from collections import deque
import sys
input = sys.stdin.readline

n = int(input())

queue = deque(i for i in range(1, n+1))
box = []

while(len(queue) > 0):
    box.append(queue.popleft())
    if(len(queue) != 0):
        queue.append(queue.popleft())


print(' '.join(map(str, box)))
