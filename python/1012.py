# 다른 사람 코드 참고
# bfs 사용

from collections import deque

t = int(input())

dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]


def bfs(i, j, visited, array):
    cnt = 0
    queue = deque()
    queue.append((i, j))
    visited[i][j] = True
    cnt += 1
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx = x+dx[i]
            ny = y+dy[i]
            if nx < 0 or nx >= n or ny < 0 or ny >= m:
                continue
            if array[nx][ny] == 1 and visited[nx][ny] == False:
                visited[nx][ny] = True
                queue.append((nx, ny))
    return cnt


for _ in range(t):
    m, n, k = map(int, input().split())
    field = [[0 for _ in range(m)] for _ in range(n)]
    visited = [[False for _ in range(m)] for _ in range(n)]

    for _ in range(k):
        x, y = map(int, input().split())
        field[y][x] = 1

    sol = 0
    for i in range(n):
        for j in range(m):
            if field[i][j] == 1 and visited[i][j] == False:
                sol += bfs(i, j, visited, field)
    print(sol)
