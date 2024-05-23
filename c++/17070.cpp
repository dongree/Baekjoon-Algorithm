#include <iostream>

using namespace std;

int N;
int board[17][17];
int ans;

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= N; }

bool possibleRow(int y, int x) {
  return inRange(y, x + 1) && board[y][x + 1] == 0;
}

bool possibleCol(int y, int x) {
  return inRange(y + 1, x) && board[y + 1][x] == 0;
}

bool possibleDiag(int y, int x) {
  return possibleRow(y, x) && possibleCol(y, x) && inRange(y + 1, x + 1) &&
         board[y + 1][x + 1] == 0;
}

void dfs(int y1, int x1, int y2, int x2) {
  if (y2 == N && x2 == N) {
    ans++;
    return;
  }

  if (y2 - y1 == 0) {  // 가로
    if (possibleRow(y2, x2)) {
      dfs(y2, x2, y2, x2 + 1);
    }
    if (possibleDiag(y2, x2)) {
      dfs(y2, x2, y2 + 1, x2 + 1);
    }
  } else if (x2 - x1 == 0) {  // 세로
    if (possibleCol(y2, x2)) {
      dfs(y2, x2, y2 + 1, x2);
    }
    if (possibleDiag(y2, x2)) {
      dfs(y2, x2, y2 + 1, x2 + 1);
    }
  } else {  // 대각선
    if (possibleRow(y2, x2)) {
      dfs(y2, x2, y2, x2 + 1);
    }
    if (possibleCol(y2, x2)) {
      dfs(y2, x2, y2 + 1, x2);
    }
    if (possibleDiag(y2, x2)) {
      dfs(y2, x2, y2 + 1, x2 + 1);
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }

  dfs(1, 1, 1, 2);

  cout << ans;

  return 0;
}