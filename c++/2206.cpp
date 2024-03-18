#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct loc {
  int y, x;
  bool isBreak;
};

int N, M;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int map[1001][1001];
int visited[1001][1001][2];

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= M; }

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      char c;
      cin >> c;
      map[i][j] = c - '0';
    }
  }

  queue<loc> q;
  q.push({1, 1, false});
  visited[1][1][false] = 1;

  while (!q.empty()) {
    int y = q.front().y;
    int x = q.front().x;
    bool isBreak = q.front().isBreak;
    q.pop();

    if (y == N && x == M) break;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (inRange(ny, nx)) {
        if (map[ny][nx] == 0 && visited[ny][nx][isBreak] == 0) {
          visited[ny][nx][isBreak] = visited[y][x][isBreak] + 1;
          q.push({ny, nx, isBreak});
        } else if (map[ny][nx] == 1 && isBreak == false) {
          visited[ny][nx][true] = visited[y][x][isBreak] + 1;
          q.push({ny, nx, true});
        }
      }
    }
  }

  int result = max(visited[N][M][false], visited[N][M][true]);

  cout << (result ? result : -1);

  return 0;
}