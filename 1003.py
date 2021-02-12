import sys
input = sys.stdin.readline

t = int(input())

fiboList = [[0 for _ in range(2)] for _ in range(41)]

fiboList[0] = [1, 0]
fiboList[1] = [0, 1]

for _ in range(t):
    n = int(input())
    if n >= 2:
        for i in range(2, n+1):
            fiboList[i][0] = fiboList[i-1][0] + fiboList[i-2][0]
            fiboList[i][1] = fiboList[i-1][1] + fiboList[i-2][1]
    print(' '.join(map(str, fiboList[n])))
