import sys
input = sys.stdin.readline

n = int(sys.stdin.readline())

stack = []

for _ in range(n):
    a = input().split()
    length = len(stack)
    if a[0] == 'push':
        stack.append(int(a[1]))
    elif a[0] == 'pop':
        if length == 0:
            print(-1)
        else:
            print(stack.pop())
    elif a[0] == 'size':
        print(length)
    elif a[0] == 'empty':
        if length == 0:
            print(1)
        else:
            print(0)
    elif a[0] == 'top':
        if length == 0:
            print(-1)
        else:
            print(stack[-1])
