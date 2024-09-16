#include <iostream>

using namespace std;

int N, K;
int board[201][201];
int temp[201][201];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= N; }

void spread(int y, int x, int n) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];

    if (inRange(ny, nx) && board[ny][nx] == 0 && temp[ny][nx] == 0) {
      temp[ny][nx] = n;
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  freopen("example.txt", "r", stdin);
  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }

  int S, X, Y;
  cin >> S >> Y >> X;

  while (S--) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        temp[i][j] = 0;
      }
    }

    for (int n = 1; n <= K; n++) {
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
          if (board[i][j] != n) continue;
          spread(i, j, n);
        }
      }
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (temp[i][j] == 0) continue;
        board[i][j] = temp[i][j];
      }
    }

    if (board[Y][X]) {
      break;
    }
  }

  cout << board[Y][X];

  return 0;
}
