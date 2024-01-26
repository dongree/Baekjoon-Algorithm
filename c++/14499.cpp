#include <iostream>

using namespace std;

int N, M, y, x, K;
int map[20][20];

int dice[6] = {0, 0, 0, 0, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

void moveDice(int cmd) {
  switch (cmd) {
    case 1: {
      int temp = dice[0];
      dice[0] = dice[3];
      dice[3] = dice[5];
      dice[5] = dice[2];
      dice[2] = temp;
      break;
    }
    case 2: {
      int temp = dice[0];
      dice[0] = dice[2];
      dice[2] = dice[5];
      dice[5] = dice[3];
      dice[3] = temp;
      break;
    }
    case 3: {
      int temp = dice[0];
      dice[0] = dice[4];
      dice[4] = dice[5];
      dice[5] = dice[1];
      dice[1] = temp;
      break;
    }
    case 4: {
      int temp = dice[0];
      dice[0] = dice[1];
      dice[1] = dice[5];
      dice[5] = dice[4];
      dice[4] = temp;
      break;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> M >> y >> x >> K;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < K; i++) {
    int cmd;
    cin >> cmd;

    int ny = y + dy[cmd - 1];
    int nx = x + dx[cmd - 1];

    if (inRange(ny, nx)) {
      moveDice(cmd);
      y = ny;
      x = nx;
      cout << dice[0] << '\n';
      if (map[ny][nx] == 0) {
        map[ny][nx] = dice[5];
      } else {
        dice[5] = map[ny][nx];
        map[ny][nx] = 0;
      }
    }
  }

  return 0;
}
