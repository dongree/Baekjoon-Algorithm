#include <algorithm>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct loc {
  int y, x, cnt;
};

char board[1001][1001];
int visited[1001][1001][11];
int N, M, K;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

queue<loc> q;

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= M; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("example.txt", "r", stdin);

  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) {
    string s;
    cin >> s;
    for (int j = 1; j <= M; j++) {
      board[i][j] = s[j - 1];
    }
  }

  q.push({1, 1, K});
  visited[1][1][K] = 1;

  while (!q.empty()) {
    int y = q.front().y;
    int x = q.front().x;
    int cnt = q.front().cnt;

    q.pop();

    if (y == N && x == M) break;

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (!inRange(ny, nx)) continue;

      if (board[ny][nx] == '0' && visited[ny][nx][cnt] == 0) {
        q.push({ny, nx, cnt});
        visited[ny][nx][cnt] = visited[y][x][cnt] + 1;
      } else if (board[ny][nx] == '1' && cnt - 1 >= 0 &&
                 visited[ny][nx][cnt - 1] == 0) {
        q.push({ny, nx, cnt - 1});
        visited[ny][nx][cnt - 1] = visited[y][x][cnt] + 1;
      }
    }
  }

  int result = 0;

  for (int i = 0; i <= K; i++) {
    result = max(result, visited[N][M][i]);
  }

  cout << (result == 0 ? -1 : result);

  return 0;
}