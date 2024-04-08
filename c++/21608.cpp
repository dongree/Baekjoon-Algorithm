// 50분 소요

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int N;
int board[21][21];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
map<int, int> loves[401];

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= N; }

void setSeat(int n, map<int, int> love) {
  vector<pair<int, int>> candidate;
  int maxCnt = 0;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j] != 0) continue;
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        int nn = board[ny][nx];
        if (inRange(ny, nx) && love[nn] == 1) {
          cnt++;
        }
      }
      if (maxCnt < cnt) {
        maxCnt = cnt;
        candidate.clear();
        candidate.push_back({i, j});
      } else if (maxCnt == cnt) {
        candidate.push_back({i, j});
      }
    }
  }

  if (candidate.size() == 1) {
    int y = candidate[0].first;
    int x = candidate[0].second;
    board[y][x] = n;
    return;
  }

  vector<pair<int, int>> candidate2;
  maxCnt = 0;
  for (int i = 0; i < candidate.size(); i++) {
    int y = candidate[i].first;
    int x = candidate[i].second;
    int cnt = 0;

    for (int k = 0; k < 4; k++) {
      int ny = y + dy[k];
      int nx = x + dx[k];
      if (inRange(ny, nx) && board[ny][nx] == 0) {
        cnt++;
      }
    }
    if (maxCnt < cnt) {
      maxCnt = cnt;
      candidate2.clear();
      candidate2.push_back({y, x});
    } else if (maxCnt == cnt) {
      candidate2.push_back({y, x});
    }
  }

  if (candidate2.size() == 1) {
    int y = candidate2[0].first;
    int x = candidate2[0].second;
    board[y][x] = n;
    return;
  }

  sort(candidate2.begin(), candidate2.end());
  int y = candidate2[0].first;
  int x = candidate2[0].second;
  board[y][x] = n;

  return;
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  int sNum = N * N;

  while (sNum--) {
    int n;
    map<int, int> love;
    cin >> n;
    for (int i = 0; i < 4; i++) {
      int l;
      cin >> l;
      love[l] = 1;
    }
    loves[n] = love;

    setSeat(n, love);
  }

  int answer = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int n = board[i][j];
      map<int, int> love = loves[n];
      int cnt = 0;
      for (int k = 0; k < 4; k++) {
        int ny = i + dy[k];
        int nx = j + dx[k];
        int nn = board[ny][nx];
        if (inRange(ny, nx) && love[nn] == 1) {
          cnt++;
        }
      }
      if (cnt == 1)
        answer += 1;
      else if (cnt == 2)
        answer += 10;
      else if (cnt == 3)
        answer += 100;
      else if (cnt == 4)
        answer += 1000;
    }
  }

  cout << answer;

  return 0;
}