# 다른 사람 풀이
# dfs 풀이

# import sys
# input = sys.stdin.readline

# n = int(input())
# m = int(input())
# s = [[0]*n for i in range(n)]
# visit = [0 for i in range(n)]

# for i in range(m):
#     a, b = map(int, input().split())
#     s[a-1][b-1] = 1
#     s[b-1][a-1] = 1


# def dfs(v):
#     visit[v] = 1
#     for i in range(n):
#         if s[v][i] == 1 and visit[i] == 0:
#             dfs(i)


# dfs(0)
# count = 0
# for i in range(1, n):
#     if visit[i] == 1:
#         count += 1
# print(count)

# ------------------------------------------------

# 내가 살짝 변경한 풀이
import sys
from collections import deque
input = sys.stdin.readline

# dfs 풀이


def dfs(v):
    visit[v] = True
    for i in range(1, n+1):
        if graph[v][i] == 1 and visit[i] == False:
            dfs(i)

# bfs 풀이
# def bfs(start):
#     queue = deque([start])
#     visit[start] = True
#     while queue:
#         v = queue.popleft()
#         for i in range(1, n+1):
#             if graph[v][i] == 1 and visit[i] == False:
#                 queue.append(i)
#                 visit[i] = True


n = int(input())
m = int(input())
graph = [[0]*(n+1) for i in range(n+1)]
visit = [False for i in range(n+1)]

for i in range(m):
    a, b = map(int, input().split())
    graph[a][b] = 1
    graph[b][a] = 1

dfs(1)
# bfs(1)
count = 0
for i in range(2, n+1):
    if visit[i] == True:
        count += 1
print(count)
