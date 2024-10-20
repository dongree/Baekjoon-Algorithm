#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int N, M;
int board[51][51];
int dist[51][51];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int result = 0;

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

void bfs(int y, int x) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      dist[i][j] = -1;
    }
  }

  queue<pair<int, int>> q;
  q.push({y, x});
  dist[y][x] = 0;

  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (inRange(ny, nx) && board[ny][nx] == 1 && dist[ny][nx] == -1) {
        dist[ny][nx] = dist[cy][cx] + 1;
        result = max(result, dist[ny][nx]);
        q.push({ny, nx});
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N >> M;

  char c;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> c;
      if (c == 'L') board[i][j] = 1;
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 0) continue;
      bfs(i, j);
    }
  }

  cout << result;

  return 0;
}