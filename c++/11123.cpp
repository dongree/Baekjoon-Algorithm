#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

int board[100][100];
bool isVisited[100][100];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int H, W;

bool inRange(int y, int x) { return 0 <= y && y < H && 0 <= x && x < W; }

void bfs(int y, int x) {
  queue<pair<int, int>> q;
  q.push({y, x});
  isVisited[y][x] = true;

  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (inRange(ny, nx) && !isVisited[ny][nx] && board[ny][nx] == 1) {
        isVisited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  int T;
  cin >> T;

  while (T--) {
    cin >> H >> W;

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        char a;
        cin >> a;
        if (a == '#')
          board[i][j] = 1;
        else
          board[i][j] = 0;
        isVisited[i][j] = false;
      }
    }

    int cnt = 0;

    for (int i = 0; i < H; i++) {
      for (int j = 0; j < W; j++) {
        if (isVisited[i][j] || board[i][j] == 0) continue;
        bfs(i, j);
        cnt++;
      }
    }

    cout << cnt << '\n';
  }

  return 0;
}