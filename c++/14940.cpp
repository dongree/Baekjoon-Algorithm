#include <iostream>
#include <queue>

using namespace std;

int n, m;
int map[1000][1000];
int answer[1000][1000];
queue<pair<int, int>> q;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }

int main() {
  freopen("example.txt", "r", stdin);

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a;
      cin >> a;
      map[i][j] = a;
      if (a != 0) answer[i][j] = -1;
      if (a == 2) {
        q.push({i, j});
        answer[i][j] = 0;
      }
    }
  }

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (inRange(ny, nx) && answer[ny][nx] == -1) {
        q.push({ny, nx});
        answer[ny][nx] = answer[y][x] + 1;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << answer[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}