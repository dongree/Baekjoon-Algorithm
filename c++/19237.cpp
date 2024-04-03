// 12:20 start

#include <iostream>
#include <vector>

using namespace std;

struct smell {
  int id, time;
};

struct shark {
  int y, x, dir;
  bool isDead;
};

int N, M, k;
int dy[5] = {0, -1, 1, 0, 0};
int dx[5] = {0, 0, 0, -1, 1};

int board[21][21];
smell smells[21][21];
int dirPriority[401][5][4];
shark sharks[401];
int sharkCnt;

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= N; }

void updatedSmell() {
  // 냄새 시간 갱신
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (smells[i][j].time > 0) {
        smells[i][j].time--;
        if (smells[i][j].time == 0) {
          smells[i][j].id = 0;
        }
      }
    }
  }

  // 새로운 냄새 정보 추가
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (board[i][j] == 0) continue;
      int num = board[i][j];
      smells[i][j].id = num;
      smells[i][j].time = k;
    }
  }
}

void moveShark() {
  for (int i = 1; i <= M; i++) {
    if (sharks[i].isDead) continue;

    int dir = sharks[i].dir;
    int y = sharks[i].y;
    int x = sharks[i].x;

    bool flag = false;
    int nextDir = dir;
    for (int k = 0; k < 4; k++) {
      int ndir = dirPriority[i][dir][k];
      int ny = y + dy[ndir];
      int nx = x + dx[ndir];

      if (inRange(ny, nx)) {
        if (smells[ny][nx].id == 0) {
          nextDir = ndir;
          break;
        } else if (!flag && smells[ny][nx].id == i) {
          nextDir = ndir;
          flag = true;
        }
      }
    }

    int ny = y + dy[nextDir];
    int nx = x + dx[nextDir];

    if (inRange(ny, nx)) {
      board[y][x] = 0;
      if (board[ny][nx] != 0) {
        sharks[i].isDead = true;
        sharkCnt--;
        continue;
      }

      board[ny][nx] = i;
      sharks[i].y = ny;
      sharks[i].x = nx;
      sharks[i].dir = nextDir;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> k;

  sharkCnt = M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int num;
      cin >> num;
      if (num != 0) {
        sharks[num].y = i;
        sharks[num].x = j;
        sharks[num].isDead = false;
        board[i][j] = num;
        smells[i][j].id = num;
        smells[i][j].time = k;
      }
    }
  }

  for (int i = 1; i <= M; i++) {
    int dir;
    cin >> dir;
    sharks[i].dir = dir;
  }

  for (int sn = 1; sn <= M; sn++) {
    for (int i = 1; i <= 4; i++) {
      for (int j = 0; j < 4; j++) {
        cin >> dirPriority[sn][i][j];
      }
    }
  }

  int t = 0;

  while (t <= 1000) {
    moveShark();
    t++;

    if (sharkCnt == 1) break;

    updatedSmell();
  }

  if (t == 1001)
    cout << -1;
  else
    cout << t;

  return 0;
}