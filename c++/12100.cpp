#include <algorithm>
#include <iostream>

using namespace std;

int board[21][21];
int N;
int answer = 0;

void swipeUp() {
  for (int i = 0; i < N; i++) {
    // 한 쪽으로 다 옮기기
    int idx = -1;
    for (int j = 0; j < N; j++) {
      if (idx != -1 && board[j][i] != 0) {
        board[idx++][i] = board[j][i];
        board[j][i] = 0;
      } else if (idx == -1 && board[j][i] == 0) {
        idx = j;
      }
    }
    // 합치기
    for (int j = 0; j < N - 1; j++) {
      int a = board[j][i];
      int b = board[j + 1][i];
      if (a == b) {
        board[j][i] = a * 2;
        board[j + 1][i] = 0;
      }
    }

    idx = -1;
    for (int j = 0; j < N; j++) {
      if (idx != -1 && board[j][i] != 0) {
        board[idx++][i] = board[j][i];
        board[j][i] = 0;
      } else if (idx == -1 && board[j][i] == 0) {
        idx = j;
      }
    }
  }
}

void swipeDown() {
  for (int i = 0; i < N; i++) {
    // 한 쪽으로 다 옮기기
    int idx = -1;
    for (int j = N - 1; j >= 0; j--) {
      if (idx != -1 && board[j][i] != 0) {
        board[idx--][i] = board[j][i];
        board[j][i] = 0;
      } else if (idx == -1 && board[j][i] == 0) {
        idx = j;
      }
    }
    // 합치기
    for (int j = N - 2; j >= 0; j--) {
      int a = board[j][i];
      int b = board[j + 1][i];
      if (a == b) {
        board[j + 1][i] = a * 2;
        board[j][i] = 0;
      }
    }

    idx = -1;
    for (int j = N - 1; j >= 0; j--) {
      if (idx != -1 && board[j][i] != 0) {
        board[idx--][i] = board[j][i];
        board[j][i] = 0;
      } else if (idx == -1 && board[j][i] == 0) {
        idx = j;
      }
    }
  }
}

void swipeLeft() {
  for (int i = 0; i < N; i++) {
    // 한 쪽으로 다 옮기기
    int idx = -1;
    for (int j = 0; j < N; j++) {
      if (idx != -1 && board[i][j] != 0) {
        board[i][idx++] = board[i][j];
        board[i][j] = 0;
      } else if (idx == -1 && board[i][j] == 0) {
        idx = j;
      }
    }
    // 합치기
    for (int j = 0; j < N - 1; j++) {
      int a = board[i][j];
      int b = board[i][j + 1];
      if (a == b) {
        board[i][j] = a * 2;
        board[i][j + 1] = 0;
      }
    }

    idx = -1;
    for (int j = 0; j < N; j++) {
      if (idx != -1 && board[i][j] != 0) {
        board[i][idx++] = board[i][j];
        board[i][j] = 0;
      } else if (idx == -1 && board[i][j] == 0) {
        idx = j;
      }
    }
  }
}

void swipeRight() {
  for (int i = 0; i < N; i++) {
    // 한 쪽으로 다 옮기기
    int idx = -1;
    for (int j = N - 1; j >= 0; j--) {
      if (idx != -1 && board[i][j] != 0) {
        board[i][idx--] = board[i][j];
        board[i][j] = 0;
      } else if (idx == -1 && board[i][j] == 0) {
        idx = j;
      }
    }
    // 합치기
    for (int j = N - 2; j >= 0; j--) {
      int a = board[i][j];
      int b = board[i][j + 1];
      if (a == b) {
        board[i][j + 1] = a * 2;
        board[i][j] = 0;
      }
    }

    idx = -1;
    for (int j = N - 1; j >= 0; j--) {
      if (idx != -1 && board[i][j] != 0) {
        board[i][idx--] = board[i][j];
        board[i][j] = 0;
      } else if (idx == -1 && board[i][j] == 0) {
        idx = j;
      }
    }
  }
}

void dfs(int cnt, int dir) {
  if (cnt == 5) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        answer = max(answer, board[i][j]);
      }
    }
    return;
  }
  if (dir == 0)
    swipeRight();
  else if (dir == 1)
    swipeLeft();
  else if (dir == 2)
    swipeDown();
  else
    swipeUp();

  for (int i = 0; i < 4; i++) {
    int temp[21][21];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        temp[i][j] = board[i][j];
      }
    }
    dfs(cnt + 1, i);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        board[i][j] = temp[i][j];
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 0; i < 4; i++) {
    int temp[21][21];
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        temp[i][j] = board[i][j];
      }
    }
    dfs(0, i);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        board[i][j] = temp[i][j];
      }
    }
  }

  cout << answer;

  return 0;
}
