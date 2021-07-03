# 1풀이

# import sys
# from collections import deque

# input = sys.stdin.readline

# n, m, v = map(int, input().split())

# s = [[] for _ in range(n+1)]
# s2 = [[] for _ in range(n+1)]

# visited = [False for _ in range(n+1)]
# visited2 = [False for _ in range(n+1)]

# for _ in range(m):
#     a, b = map(int, input().split())
#     s[a][b] = 1
#     s[b][a] = 1
#     s2[a][b] = 1
#     s2[b][a] = 1


# def dfs(v):
#     visited[v] = True
#     print(v, end=' ')
#     for i in range(1, n+1):
#         if s[v][i] == 1 and visited[i] == False:
#             dfs(i)


# def bfs(start):
#     queue = deque([start])
#     visited2[start] = True
#     while(queue):
#         v = queue.popleft()
#         print(v, end=' ')
#         for i in range(1, n+1):
#             if s2[v][i] == 1 and visited2[i] == False:
#                 queue.append(i)
#                 visited2[i] = True

# dfs(v)
# print()
# bfs(v)


# 2 풀이
# 미세하지만 2풀이가 더 효율적
import sys
from collections import deque

input = sys.stdin.readline

n, m, v = map(int, input().split())

s = [[] for _ in range(n+1)]
s2 = [[] for _ in range(n+1)]

visited = [False for _ in range(n+1)]
visited2 = [False for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    s[a].append(b)
    s[b].append(a)
    s2[a].append(b)
    s2[b].append(a)

for i in range(1, len(s)):
    s[i].sort()
    s2[i].sort()


def dfs(v):
    visited[v] = True
    print(v, end=' ')
    for i in s[v]:
        if visited[i] == False:
            dfs(i)


def bfs(start):
    queue = deque([start])
    visited2[start] = True
    while(queue):
        v = queue.popleft()
        print(v, end=' ')
        for i in s[v]:
            if visited2[i] == False:
                queue.append(i)
                visited2[i] = True


dfs(v)
print()
bfs(v)
