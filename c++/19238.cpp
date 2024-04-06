// 1시간 6분 소요

#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct customer {
  int id, y, x, desY, desX;
  bool isDone;
};

customer customers[401];

int N, M, K;
int board[21][21];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int doneCnt;

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= N; }

int bfs(int sy, int sx, int desY, int desX) {
  int visited[21][21];
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      visited[i][j] = -1;
    }
  }
  queue<pair<int, int>> q;
  q.push({sy, sx});
  visited[sy][sx] = 0;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;

    if (y == desY && x == desX) {
      return visited[y][x];
    }

    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (inRange(ny, nx) && board[ny][nx] == 0 && visited[ny][nx] == -1) {
        visited[ny][nx] = visited[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }
  return -1;
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }

  int sy, sx;
  cin >> sy >> sx;

  for (int i = 1; i <= M; i++) {
    int y, x, desY, desX;
    cin >> y >> x >> desY >> desX;
    customers[i].id = i;
    customers[i].y = y;
    customers[i].x = x;
    customers[i].desY = desY;
    customers[i].desX = desX;
    customers[i].isDone = false;
  }

  doneCnt = M;

  while (doneCnt > 0) {
    // 현재 택시 위치로부터 최단 거리에 위치한 승객 찾기
    vector<customer> v;
    int minDist = 1e9;
    for (int i = 1; i <= M; i++) {
      if (customers[i].isDone) continue;
      int dist = bfs(sy, sx, customers[i].y, customers[i].x);
      if (dist == -1) {
        cout << -1;
        return 0;
      }
      if (dist < minDist) {
        minDist = dist;
        v.clear();
        v.push_back(customers[i]);
      } else if (dist == minDist) {
        v.push_back(customers[i]);
      }
    }

    customer nc = v[0];
    for (int i = 1; i < v.size(); i++) {
      if (v[i].y < nc.y || (v[i].y == nc.y && v[i].x < nc.x)) {
        nc = v[i];
      }
    }

    // 택시 to 승객위치
    K -= minDist;
    if (K < 0) {
      cout << -1;
      return 0;
    }
    // 승객위치 to 목적지
    int dist = bfs(nc.y, nc.x, nc.desY, nc.desX);
    if (dist == -1) {
      cout << -1;
      return 0;
    }
    K -= dist;
    if (K < 0) {
      cout << -1;
      return 0;
    }
    K += 2 * dist;

    sy = nc.desY;
    sx = nc.desX;
    customers[nc.id].isDone = true;

    doneCnt--;
  }

  cout << K;

  return 0;
}