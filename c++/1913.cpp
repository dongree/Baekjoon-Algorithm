#include <iostream>

using namespace std;

int board[1000][1000];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  int cy = N / 2 + 1;
  int cx = N / 2 + 1;

  int n = 1;
  int dir = 0;
  int limit = 1;
  int k = 0;
  int two = 2;

  while (true) {
    board[cy][cx] = n++;

    if (cy == 1 && cx == 1) break;

    cy += dy[dir];
    cx += dx[dir];
    k++;

    if (k == limit) {
      two--;
      k = 0;
      dir = (dir + 1) % 4;
    }

    if (two == 0) {
      limit++;
      two = 2;
    }
  }

  int ty, tx;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j] == M) {
        ty = i;
        tx = j;
      }
      cout << board[i][j] << ' ';
    }
    cout << '\n';
  }

  cout << ty << ' ' << tx;

  return 0;
}