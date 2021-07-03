from collections import deque
import sys

input = sys.stdin.readline

n = int(input())

deque = deque()

for _ in range(n):
    a = input().split()
    if a[0] == 'push_front':
        deque.appendleft(a[1])
    elif a[0] == 'push_back':
        deque.append(a[1])
    elif a[0] == 'pop_front':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque.popleft())
    elif a[0] == 'pop_back':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque.pop())
    elif a[0] == 'size':
        print(len(deque))
    elif a[0] == 'empty':
        if len(deque) == 0:
            print(1)
        else:
            print(0)
    elif a[0] == 'front':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[0])
    elif a[0] == 'back':
        if len(deque) == 0:
            print(-1)
        else:
            print(deque[-1])
