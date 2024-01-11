#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

int n, m, answer;
int map[8][8];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

void bfs() {
  vector<vector<int>> tempMap;
  for (int i = 0; i < n; i++) {
    vector<int> v;
    for (int j = 0; j < m; j++) {
      v.push_back(map[i][j]);
    }
    tempMap.push_back(v);
  }

  queue<pair<int, int>> q;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tempMap[i][j] == 2) q.push(make_pair(i, j));
    }
  }

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (0 <= ny && ny < n && 0 <= nx && nx < m && tempMap[ny][nx] == 0) {
        tempMap[ny][nx] = 2;
        q.push(make_pair(ny, nx));
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (tempMap[i][j] == 0) cnt++;
    }
  }

  answer = max(answer, cnt);
}

void dfs(int y, int x, int cnt) {
  if (cnt == 3) {
    bfs();
    return;
  }

  for (int i = y; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == y && j <= x) continue;
      if (map[i][j] == 0) {
        map[i][j] = 1;
        dfs(i, j, cnt + 1);
        map[i][j] = 0;
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  dfs(0, -1, 0);

  cout << answer;

  return 0;
}