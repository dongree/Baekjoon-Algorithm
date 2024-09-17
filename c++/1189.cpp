#include <iostream>
#include <queue>

using namespace std;

int board[5][5];
bool isVisited[5][5];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
int R, C, K;
int result;

bool inRange(int y, int x) { return 0 <= y && y < R && 0 <= x && x < C; }

void dfs(int y, int x, int cnt) {
  if (cnt > K) {
    return;
  }

  if (y == 0 && x == C - 1 && cnt == K) {
    result++;
    return;
  }

  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (inRange(ny, nx) && !isVisited[ny][nx] && !board[ny][nx]) {
      isVisited[ny][nx] = true;
      dfs(ny, nx, cnt + 1);
      isVisited[ny][nx] = false;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> R >> C >> K;

  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      char c;
      cin >> c;

      if (c == 'T') {
        board[i][j] = 1;
      }
    }
  }

  isVisited[R - 1][0] = true;
  dfs(R - 1, 0, 1);

  cout << result;

  return 0;
}