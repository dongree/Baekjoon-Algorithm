// 2시간 40분 소요

#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

deque<pair<int, pair<int, int>>> board[101][101];  // {크기, {속력, 이동방향}}
int R, C, M;
int answer;

bool compare(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
  return a.first > b.first;
}

void moveShark() {
  bool isVisited[10001] = {false};

  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (board[i][j].size() != 0) {
        int size = board[i][j].back().first;
        int speed = board[i][j].back().second.first;
        int dir = board[i][j].back().second.second;

        if (isVisited[size]) continue;
        isVisited[size] = true;

        board[i][j].pop_back();

        switch (dir) {
          case 1: {
            int y;
            int d = dir;
            if (i - 1 >= speed) {
              y = i - speed;
              if (i - 1 == speed) d = 2;
            } else {
              int temp = speed;
              temp -= (i - 1);
              int cnt = 0;
              while (temp > R - 1) {
                temp -= (R - 1);
                cnt++;
              }
              if (cnt % 2 == 0) {
                y = 1 + temp;
                d = 2;
              } else {
                y = R - temp;
              }
            }
            board[y][j].push_front({size, {speed, d}});
            break;
          }
          case 2: {
            int y;
            int d = dir;
            if (R - i >= speed) {
              y = i + speed;
              if (R - i == speed) d = 1;
            } else {
              int temp = speed;
              temp -= (R - i);
              int cnt = 0;
              while (temp > R - 1) {
                temp -= (R - 1);
                cnt++;
              }
              if (cnt % 2 == 0) {
                y = R - temp;
                d = 1;
              } else {
                y = 1 + temp;
              }
            }
            board[y][j].push_front({size, {speed, d}});
            break;
          }
          case 3: {
            int x;
            int d = dir;
            if (C - j >= speed) {
              x = j + speed;
              if (C - j == speed) d = 4;
            } else {
              int temp = speed;
              temp -= (C - j);
              int cnt = 0;
              while (temp > C - 1) {
                temp -= (C - 1);
                cnt++;
              }
              if (cnt % 2 == 0) {
                x = C - temp;
                d = 4;
              } else {
                x = 1 + temp;
              }
            }
            board[i][x].push_front({size, {speed, d}});
            break;
          }
          case 4: {
            int x;
            int d = dir;
            if (j - 1 >= speed) {
              x = j - speed;
              if (j - 1 == speed) d = 3;
            } else {
              int temp = speed;
              temp -= (j - 1);
              int cnt = 0;
              while (temp > C - 1) {
                temp -= (C - 1);
                cnt++;
              }
              if (cnt % 2 == 0) {
                x = 1 + temp;
                d = 3;
              } else {
                x = C - temp;
              }
            }
            board[i][x].push_front({size, {speed, d}});
            break;
          }
          default:
            break;
        }
      }
    }
  }

  // 상어 중복 제거
  for (int i = 1; i <= R; i++) {
    for (int j = 1; j <= C; j++) {
      if (board[i][j].size() > 1) {
        sort(board[i][j].begin(), board[i][j].end(), compare);

        while (board[i][j].size() > 1) {
          board[i][j].pop_back();
        }
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> R >> C >> M;

  while (M--) {
    int r, c, s, d, z;
    cin >> r >> c >> s >> d >> z;
    board[r][c].push_front({z, {s, d}});
  }

  int fishKingLoc = 0;

  while (fishKingLoc < C) {
    // 낚시왕 이동
    fishKingLoc++;

    // 상어 잡기
    for (int i = 1; i <= R; i++) {
      if (board[i][fishKingLoc].size() != 0) {
        answer += board[i][fishKingLoc][0].first;
        board[i][fishKingLoc].pop_back();
        break;
      }
    }

    // 상어 이동
    moveShark();
  }

  cout << answer;

  return 0;
}