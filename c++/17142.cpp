// 소요 시간 : 58분

#include <iostream>
#include <queue>

using namespace std;

int board[50][50];
bool isVisited[2500];
int N, M;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int answer = 1e9;

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

void bfs() {
  queue<pair<int, int>> q;
  int dist[50][50];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (board[i][j] == 1)
        dist[i][j] = -1;  // 벽
      else if (board[i][j] == 2)
        dist[i][j] = -2;  // 비활성 바이러스
      else
        dist[i][j] = -10;  // 빈 칸
    }
  }

  for (int i = 0; i < N * N; i++) {
    if (isVisited[i]) {
      dist[i / N][i % N] = 0;
      q.push({i / N, i % N});
    }
  }

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (inRange(ny, nx)) {
        if (dist[ny][nx] == -10) {
          dist[ny][nx] = dist[y][x] + 1;
          q.push({ny, nx});
        } else if (dist[ny][nx] == -2) {
          bool isEnd = true;
          for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
              if (dist[i][j] == -10) {
                isEnd = false;
                break;
              }
            }
            if (!isEnd) break;
          }
          if (!isEnd) {
            dist[ny][nx] = dist[y][x] + 1;
            q.push({ny, nx});
          }
        }
      }
    }
  }

  int maxValue = 0;
  bool isEnd = true;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (dist[i][j] == -10) {
        isEnd = false;
        break;
      }
      if (dist[i][j] > 0 && dist[i][j] > maxValue) {
        maxValue = dist[i][j];
      }
    }
    if (!isEnd) break;
  }

  if (isEnd && maxValue < answer) {
    answer = maxValue;
  }
}

void dfs(int curr, int cnt) {
  if (cnt == M) {
    bfs();
    return;
  }

  for (int i = curr; i < N * N; i++) {
    int y = i / N;
    int x = i % N;

    if (board[y][x] == 2) {
      isVisited[i] = true;
      dfs(i + 1, cnt + 1);
      isVisited[i] = false;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  dfs(0, 0);

  cout << ((answer == 1e9) ? -1 : answer);

  return 0;
}