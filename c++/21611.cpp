// 1시간 30분 소요

#include <iostream>
#include <vector>

using namespace std;

int board[50][50];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int N, M;

int magicY[5] = {0, -1, 1, 0, 0};
int magicX[5] = {0, 0, 0, -1, 1};
int marbleBombCnt[4];

void breakMarble(int d, int s) {
  int cy = (N + 1) / 2;
  int cx = (N + 1) / 2;

  while (s--) {
    cy += magicY[d];
    cx += magicX[d];
    board[cy][cx] = 0;
  }
}

void moveMarble() {
  vector<int> temp;

  int cy = (N + 1) / 2;
  int cx = (N + 1) / 2;
  int cd = 0;
  int cs = 1;

  for (int t = 0; t < N - 1; t++) {
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < cs; i++) {
        cy += dy[cd];
        cx += dx[cd];
        if (board[cy][cx] != 0) {
          temp.push_back(board[cy][cx]);
        }
      }
      cd = (cd + 1) % 4;
    }
    cs++;
  }
  for (int i = N - 1; i >= 1; i--) {
    if (board[1][i] != 0) {
      temp.push_back(board[1][i]);
    }
  }

  cy = (N + 1) / 2;
  cx = (N + 1) / 2;
  cd = 0;
  cs = 1;
  int idx = 0;

  for (int t = 0; t < N - 1; t++) {
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < cs; i++) {
        cy += dy[cd];
        cx += dx[cd];
        if (idx < temp.size()) {
          board[cy][cx] = temp[idx];
          idx++;
        } else {
          board[cy][cx] = 0;
        }
      }
      cd = (cd + 1) % 4;
    }
    cs++;
  }
  for (int i = N - 1; i >= 1; i--) {
    if (idx < temp.size()) {
      board[1][i] = temp[idx];
      idx++;
    } else {
      board[1][i] = 0;
    }
  }
}

bool bombMarble() {
  bool isBomb = false;

  int cy = (N + 1) / 2;
  int cx = (N + 1) / 2;
  int cd = 0;
  int cs = 1;

  vector<pair<int, int>> v;
  int cur = 0;

  for (int t = 0; t < N - 1; t++) {
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < cs; i++) {
        cy += dy[cd];
        cx += dx[cd];
        if (cur == board[cy][cx]) {
          v.push_back({cy, cx});
        } else {
          if (v.size() >= 4) {
            isBomb = true;
            marbleBombCnt[cur] += v.size();
            for (int j = 0; j < v.size(); j++) {
              int y = v[j].first;
              int x = v[j].second;
              board[y][x] = 0;
            }
          }
          cur = board[cy][cx];

          v.clear();
          v.push_back({cy, cx});
        }
      }
      cd = (cd + 1) % 4;
    }
    cs++;
  }

  for (int i = N - 1; i >= 1; i--) {
    if (cur == board[1][i]) {
      v.push_back({1, i});
    } else {
      if (v.size() >= 4) {
        isBomb = true;
        marbleBombCnt[cur] += v.size();
        for (int j = 0; j < v.size(); j++) {
          int y = v[j].first;
          int x = v[j].second;
          board[y][x] = 0;
        }
      }
      cur = board[1][i];
      v.clear();
      v.push_back({1, i});
    }
  }

  if (v.size() >= 4 && board[1][1] != 0) {
    isBomb = true;
    marbleBombCnt[board[v[0].first][v[0].second]] += v.size();
    for (int j = 0; j < v.size(); j++) {
      int y = v[j].first;
      int x = v[j].second;
      board[y][x] = 0;
    }
  }

  return isBomb;
}

void changeMarble() {
  vector<int> temp;

  int cy = (N + 1) / 2;
  int cx = (N + 1) / 2;
  int cd = 0;
  int cs = 1;

  int curr = board[cy][cx - 1];
  int cnt = 0;
  bool isDone = false;

  for (int t = 0; t < N - 1; t++) {
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < cs; i++) {
        cy += dy[cd];
        cx += dx[cd];
        if (board[cy][cx] == 0) {
          temp.push_back(cnt);
          temp.push_back(curr);
          isDone = true;
          break;
        }
        if (board[cy][cx] != curr) {
          temp.push_back(cnt);
          temp.push_back(curr);
          cnt = 1;
          curr = board[cy][cx];
        } else {
          cnt++;
        }
      }
      if (isDone) break;
      cd = (cd + 1) % 4;
    }
    if (isDone) break;
    cs++;
  }
  for (int i = N - 1; i >= 1; i--) {
    if (isDone) break;
    if (board[cy][cx] == 0) {
      temp.push_back(cnt);
      temp.push_back(curr);
      isDone = true;
      break;
    }
    if (board[1][i] != curr) {
      temp.push_back(cnt);
      temp.push_back(curr);
      cnt = 1;
      curr = board[1][i];
    } else {
      cnt++;
    }
  }

  cy = (N + 1) / 2;
  cx = (N + 1) / 2;
  cd = 0;
  cs = 1;
  int idx = 0;

  for (int t = 0; t < N - 1; t++) {
    for (int k = 0; k < 2; k++) {
      for (int i = 0; i < cs; i++) {
        cy += dy[cd];
        cx += dx[cd];
        if (idx < temp.size()) {
          board[cy][cx] = temp[idx];
          idx++;
        } else {
          board[cy][cx] = 0;
        }
      }
      cd = (cd + 1) % 4;
    }
    cs++;
  }
  for (int i = N - 1; i >= 1; i--) {
    if (idx < temp.size()) {
      board[1][i] = temp[idx];
      idx++;
    } else {
      board[1][i] = 0;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }

  while (M--) {
    int d, s;
    cin >> d >> s;

    breakMarble(d, s);
    moveMarble();

    while (true) {
      if (!bombMarble()) break;
      moveMarble();
    }

    changeMarble();
  }

  int answer = marbleBombCnt[1] + marbleBombCnt[2] * 2 + marbleBombCnt[3] * 3;
  cout << answer;

  return 0;
}