import sys
input = sys.stdin.readline

n = int(input())

s = set()

for _ in range(n):
    a = input().split()
    if a[0] == 'add':
        if not int(a[1]) in s:
            s.add(int(a[1]))
    elif a[0] == 'remove':
        if int(a[1]) in s:
            s.remove(int(a[1]))
    elif a[0] == 'check':
        if int(a[1]) in s:
            print(1)
        else:
            print(0)
    elif a[0] == 'toggle':
        if int(a[1]) in s:
            s.remove(int(a[1]))
        else:
            s.add(int(a[1]))
    elif a[0] == 'all':
        s = set([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
                 12, 13, 14, 15, 16, 17, 18, 19, 20])
    elif a[0] == 'empty':
        s = set()
