// 9:32 start

#include <iostream>
#include <queue>

using namespace std;

int N, M, K;
int board[21][21];

int dice[6] = {1, 2, 3, 4, 5, 6};  // 워, 뒤, 오, 왼, 앞, 밑
int dy[4] = {0, 1, 0, -1};         // 동, 남, 서, 북
int dx[4] = {1, 0, -1, 0};
int answer;

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= M; }

void moveDice(int dir) {
  switch (dir) {
    case 0: {
      int tempTop = dice[0];
      int tempRight = dice[2];
      int tempLeft = dice[3];
      int tempBottom = dice[5];

      dice[0] = tempLeft;
      dice[2] = tempTop;
      dice[3] = tempBottom;
      dice[5] = tempRight;
      break;
    }
    case 1: {
      int tempTop = dice[0];
      int tempBack = dice[1];
      int tempFront = dice[4];
      int tempBottom = dice[5];

      dice[0] = tempBack;
      dice[1] = tempBottom;
      dice[4] = tempTop;
      dice[5] = tempFront;
      break;
    }
    case 2: {
      int tempTop = dice[0];
      int tempRight = dice[2];
      int tempLeft = dice[3];
      int tempBottom = dice[5];

      dice[0] = tempRight;
      dice[2] = tempBottom;
      dice[3] = tempTop;
      dice[5] = tempLeft;
      break;
    }
    case 3: {
      int tempTop = dice[0];
      int tempBack = dice[1];
      int tempFront = dice[4];
      int tempBottom = dice[5];

      dice[0] = tempFront;
      dice[1] = tempTop;
      dice[4] = tempBottom;
      dice[5] = tempBack;
      break;
    }

    default:
      break;
  }
}

int bfs(int y, int x) {
  bool isVisited[21][21] = {false};

  queue<pair<int, int>> q;
  q.push({y, x});
  isVisited[y][x] = true;
  int cnt = 1;

  while (!q.empty()) {
    int cy = q.front().first;
    int cx = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int ny = cy + dy[i];
      int nx = cx + dx[i];

      if (inRange(ny, nx) && !isVisited[ny][nx] &&
          board[ny][nx] == board[y][x]) {
        cnt++;
        isVisited[ny][nx] = true;
        q.push({ny, nx});
      }
    }
  }

  return cnt * board[y][x];
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> M >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> board[i][j];
    }
  }

  int currDir = 0;
  int cy = 1;
  int cx = 1;

  while (K--) {
    int ny = cy + dy[currDir];
    int nx = cx + dx[currDir];
    if (!inRange(ny, nx)) {
      currDir = (currDir + 2) % 4;
      ny = (cy + dy[currDir]);
      nx = (cx + dx[currDir]);
    }
    moveDice(currDir);
    // 점수
    cy = ny;
    cx = nx;
    int score = bfs(cy, cx);
    answer += score;

    /* 방향 결정 */
    int A = dice[5];
    int B = board[cy][cx];
    if (A > B)
      currDir = (currDir + 1) % 4;
    else if (A < B)
      currDir = (currDir == 0 ? 3 : (currDir - 1));
  }

  cout << answer;

  return 0;
}