#include <iostream>
#include <string>

using namespace std;

int board[200][200];
int R, C, N;
int t = 2;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void printBoard() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cout << (board[i][j] == -1 ? '.' : 'O');
    }
    cout << '\n';
  }
}

bool inRange(int y, int x) { return 0 <= y && y < R && 0 <= x && x < C; }

void installBomb() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (board[i][j] == -1) board[i][j] = t;
    }
  }
}

void bomb() {
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      if (t - board[i][j] != 3) continue;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];

        if (inRange(ny, nx) && t - board[ny][nx] != 3) {
          board[ny][nx] = -1;
        }
      }
      board[i][j] = -1;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> R >> C >> N;

  for (int i = 0; i < R; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < s.length(); j++) {
      if (s[j] == '.')
        board[i][j] = -1;
      else
        board[i][j] = 0;
    }
  }

  while (t <= N) {
    installBomb();
    if (t == N) break;
    t++;

    bomb();
    if (t == N) break;
    t++;
  }
  printBoard();

  return 0;
}