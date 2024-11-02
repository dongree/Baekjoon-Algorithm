#include <iostream>

using namespace std;

int board[5][5];
int cnt = 1;
int N;
int num = 1;

int dy[4] = {1, 1, -1, -1};
int dx[4] = {1, -1, 1, -1};

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= N; }
bool flag = false;

void printBoard() {
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }
}

void dfs(int n, int cnt) {
  if (flag) return;

  if (cnt == N * N) {
    printBoard();
    flag = true;
    return;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j] != 0) continue;
      board[i][j] = n;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        if (inRange(ny, nx) && board[i][nx] == 0 && board[ny][j] == 0) {
          board[i][nx] = n;
          board[ny][j] = n;
          dfs(n + 1, cnt + 3);
          board[i][nx] = 0;
          board[ny][j] = 0;
        }
      }
      board[i][j] = 0;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int K, x, y;
  cin >> K >> x >> y;

  N = 2 * K;

  board[N - y + 1][x] = -1;

  dfs(1, 1);

  if (!flag) cout << -1;

  return 0;
}