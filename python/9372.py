# 다른 사람 풀이 참고
# 모든 나라는 연결되어 있으므로 최소 개수는 n-1!

import sys
input = sys.stdin.readline

t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    for i in range(m):
        a, b = map(int, input().split())
    print(n-1)
