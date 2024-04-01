// 55분 소요

#include <iostream>
#include <vector>

using namespace std;

int answer;

int dy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};
int dx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};

bool inRange(int y, int x) { return 0 <= y && y < 4 && 0 <= x && x < 4; }

void dfs(int sy, int sx, int score, vector<vector<pair<int, int>>> board) {
  if (score > answer) answer = score;

  // 물고기 이동
  int num = 1;
  while (num <= 16) {
    bool flag = false;

    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (board[i][j].first == num) {
          flag = true;
          int dir = board[i][j].second;
          int idx = 0;
          while (idx <= 7) {
            int ndir = (dir + idx - 1) % 8 + 1;
            int ny = i + dy[ndir];
            int nx = j + dx[ndir];

            if (inRange(ny, nx) && board[ny][nx].first != -1) {
              board[i][j].first = board[ny][nx].first;
              board[i][j].second = board[ny][nx].second;

              board[ny][nx].first = num;
              board[ny][nx].second = ndir;
              break;
            }
            idx++;
          }

          break;
        }
      }
      if (flag) break;
    }
    num++;
  }

  // 상어 이동
  int sdir = board[sy][sx].second;

  for (int i = 1; i <= 3; i++) {
    int nsy = sy + dy[sdir] * i;
    int nsx = sx + dx[sdir] * i;

    if (inRange(nsy, nsx) && board[nsy][nsx].first != 0) {
      board[sy][sx].first = 0;
      board[sy][sx].second = 0;
      int tempNum = board[nsy][nsx].first;
      board[nsy][nsx].first = -1;
      dfs(nsy, nsx, score + tempNum, board);
      board[nsy][nsx].first = tempNum;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  vector<vector<pair<int, int>>> board;

  for (int i = 0; i < 4; i++) {
    vector<pair<int, int>> v;
    for (int j = 0; j < 4; j++) {
      int num, dir;
      cin >> num >> dir;
      v.push_back({num, dir});
    }
    board.push_back(v);
  }

  int score = board[0][0].first;
  board[0][0].first = -1;

  dfs(0, 0, score, board);

  cout << answer;

  return 0;
}