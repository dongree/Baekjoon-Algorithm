// 58분 소요

#include <iostream>

using namespace std;

int board[10][10];
int score = 0;

void fillGreenBoard(int t, int x, int y) {
  switch (t) {
    case 1: {
      for (int i = 4; i <= 9; i++) {
        if (board[i][y] == 1) {
          board[i - 1][y] = 1;
          break;
        }
        if (i == 9) {
          board[i][y] = 1;
        }
      }
      break;
    }
    case 2: {
      for (int i = 4; i <= 9; i++) {
        if (board[i][y] == 1 || board[i][y + 1] == 1) {
          board[i - 1][y] = 1;
          board[i - 1][y + 1] = 1;
          break;
        }

        if (i == 9) {
          board[i][y] = 1;
          board[i][y + 1] = 1;
        }
      }
      break;
    }
    case 3: {
      for (int i = 4; i <= 9; i++) {
        if (board[i][y] == 1) {
          board[i - 1][y] = 1;
          board[i - 2][y] = 1;
          break;
        }

        if (i == 9) {
          board[i - 1][y] = 1;
          board[i][y] = 1;
        }
      }
      break;
    }
    default:
      break;
  }
}

void fillBlueBoard(int t, int x, int y) {
  switch (t) {
    case 1: {
      for (int j = 4; j <= 9; j++) {
        if (board[x][j] == 1) {
          board[x][j - 1] = 1;
          break;
        }
        if (j == 9) {
          board[x][j] = 1;
        }
      }
      break;
    }
    case 2: {
      for (int j = 4; j <= 9; j++) {
        if (board[x][j] == 1) {
          board[x][j - 1] = 1;
          board[x][j - 2] = 1;
          break;
        }
        if (j == 9) {
          board[x][j] = 1;
          board[x][j - 1] = 1;
        }
      }
      break;
    }
    case 3: {
      for (int j = 4; j <= 9; j++) {
        if (board[x][j] == 1 || board[x + 1][j] == 1) {
          board[x][j - 1] = 1;
          board[x + 1][j - 1] = 1;
          break;
        }
        if (j == 9) {
          board[x][j] = 1;
          board[x + 1][j] = 1;
        }
      }
      break;
    }
    default:
      break;
  }
}

void scanGreen() {
  for (int i = 6; i <= 9; i++) {
    bool isFill = true;
    for (int j = 0; j <= 3; j++) {
      if (board[i][j] == 0) {
        isFill = false;
        break;
      }
    }
    if (isFill) {
      score++;
      // 해당 칸까지 당기기
      for (int k = i; k >= 4; k--) {
        for (int j = 0; j <= 3; j++) {
          board[k][j] = board[k - 1][j];
        }
      }
    }
  }
}

void scanBlue() {
  for (int i = 6; i <= 9; i++) {
    bool isFill = true;
    for (int j = 0; j <= 3; j++) {
      if (board[j][i] == 0) {
        isFill = false;
        break;
      }
    }
    if (isFill) {
      score++;
      // 해당 칸까지 당기기
      for (int k = i; k >= 4; k--) {
        for (int j = 0; j <= 3; j++) {
          board[j][k] = board[j][k - 1];
        }
      }
    }
  }
}

void scanSpecialGreen() {
  int cnt = 0;
  for (int i = 4; i <= 5; i++) {
    for (int j = 0; j <= 3; j++) {
      if (board[i][j] == 1) {
        if (i == 4)
          cnt = 2;
        else
          cnt = 1;
        break;
      }
    }
    if (cnt > 0) break;
  }

  for (int i = 9; i >= 6; i--) {
    for (int j = 0; j <= 3; j++) {
      board[i][j] = board[i - cnt][j];
    }
  }

  for (int i = 4; i <= 5; i++) {
    for (int j = 0; j <= 3; j++) {
      board[i][j] = 0;
    }
  }
}

void scanSpecialBlue() {
  int cnt = 0;
  for (int i = 4; i <= 5; i++) {
    for (int j = 0; j <= 3; j++) {
      if (board[j][i] == 1) {
        if (i == 4)
          cnt = 2;
        else
          cnt = 1;
        break;
      }
    }
    if (cnt > 0) break;
  }

  for (int i = 9; i >= 6; i--) {
    for (int j = 0; j <= 3; j++) {
      board[j][i] = board[j][i - cnt];
    }
  }

  for (int i = 4; i <= 5; i++) {
    for (int j = 0; j <= 3; j++) {
      board[j][i] = 0;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  while (N--) {
    int t, x, y;
    cin >> t >> x >> y;

    fillGreenBoard(t, x, y);
    scanGreen();
    scanSpecialGreen();

    fillBlueBoard(t, x, y);
    scanBlue();
    scanSpecialBlue();
  }

  int cnt = 0;

  for (int i = 6; i <= 9; i++) {
    for (int j = 0; j <= 3; j++) {
      if (board[i][j] == 1) cnt++;
      if (board[j][i] == 1) cnt++;
    }
  }

  cout << score << '\n' << cnt;

  return 0;
}