#include <iostream>
#include <queue>
#include <string>

using namespace std;

char board[5][5];
bool isVisited[5][5];
int answer = 0;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool isConnected() {
  int sy, sx;
  bool flag = false;
  for (int i = 0; i < 5; i++) {
    if (flag) break;
    for (int j = 0; j < 5; j++) {
      if (isVisited[i][j]) {
        sy = i;
        sx = j;
        flag = true;
        break;
      }
    }
  }

  bool isSubVisited[5][5] = {false};
  queue<pair<int, int>> q;
  q.push({sy, sx});
  isSubVisited[sy][sx] = true;
  int cnt = 1;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (0 <= ny && ny < 5 && 0 <= nx && nx < 5 && isVisited[ny][nx] &&
          !isSubVisited[ny][nx]) {
        isSubVisited[ny][nx] = true;
        cnt++;
        q.push({ny, nx});
      }
    }
  }

  return cnt == 7;
}

void dfs(int cur, int yCnt, int sCnt) {
  if (yCnt >= 4) return;

  if (yCnt + sCnt == 7) {
    if (isConnected()) answer++;
    return;
  }

  for (int i = cur; i < 25; i++) {
    int y = i / 5;
    int x = i % 5;

    if (!isVisited[y][x]) {
      isVisited[y][x] = true;
      if (board[y][x] == 'S')
        dfs(i + 1, yCnt, sCnt + 1);
      else
        dfs(i + 1, yCnt + 1, sCnt);
      isVisited[y][x] = false;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> board[i][j];
    }
  }

  dfs(0, 0, 0);

  cout << answer;

  return 0;
}