#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int board[100][100];
bool isVisited[100][100];
int N, M;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  isVisited[y][x] = true;

  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];
      if (inRange(ny, nx) && !isVisited[ny][nx] && board[ny][nx] == 0) {
        isVisited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
}

int getCheese() {
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (board[i][j] == 1) cnt++;
    }
  }

  return cnt;
}

bool willMelt(int y, int x) {
  int cnt = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (inRange(ny, nx) && isVisited[ny][nx]) cnt++;
  }
  if (cnt >= 2) return true;
  return false;
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> board[i][j];
    }
  }

  int t = 0;
  while (getCheese() != 0) {
    memset(isVisited, false, sizeof(isVisited));
    bfs(0, 0);

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        if (board[i][j] == 1 && willMelt(i, j)) {
          board[i][j] = 0;
        }
      }
    }

    t++;
  }

  cout << t;

  return 0;
}