#include <iostream>
#include <vector>

using namespace std;

int dy[5] = {0, 0, 0, -1, 1};
int dx[5] = {0, 1, -1, 0, 0};

int board[13][13];
int mal[11][3];
vector<int> stackArr[13][13];
int N, K;

bool inRange(int y, int x) { return 1 <= y && y <= N && 1 <= x && x <= N; }

void white(int currY, int currX, int ny, int nx, int num) {
  if (stackArr[currY][currX].back() != num) {
    vector<int> v;
    while (true) {
      int poped = stackArr[currY][currX].back();
      stackArr[currY][currX].pop_back();
      v.push_back(poped);
      mal[poped][0] = ny;
      mal[poped][1] = nx;
      if (poped == num) break;
    }
    while (!v.empty()) {
      stackArr[ny][nx].push_back(v.back());
      v.pop_back();
    }
  } else {
    int poped = stackArr[currY][currX].back();
    stackArr[currY][currX].pop_back();
    stackArr[ny][nx].push_back(poped);
    mal[poped][0] = ny;
    mal[poped][1] = nx;
  }
}

void red(int currY, int currX, int ny, int nx, int num) {
  if (stackArr[currY][currX].back() != num) {
    while (true) {
      int poped = stackArr[currY][currX].back();
      stackArr[currY][currX].pop_back();
      stackArr[ny][nx].push_back(poped);

      mal[poped][0] = ny;
      mal[poped][1] = nx;
      if (poped == num) break;
    }
  } else {
    int poped = stackArr[currY][currX].back();
    stackArr[currY][currX].pop_back();
    stackArr[ny][nx].push_back(poped);
    mal[poped][0] = ny;
    mal[poped][1] = nx;
  }
}

void blue(int currY, int currX, int ny, int nx, int num, int dirNum) {
  if (dirNum == 1)
    mal[num][2] = 2;
  else if (dirNum == 2)
    mal[num][2] = 1;
  else if (dirNum == 3)
    mal[num][2] = 4;
  else if (dirNum == 4)
    mal[num][2] = 3;
  int newNy = currY + dy[mal[num][2]];
  int newNx = currX + dx[mal[num][2]];
  if (inRange(newNy, newNx)) {
    int next = board[newNy][newNx];
    switch (next) {
      case 0: {
        white(currY, currX, newNy, newNx, num);
        break;
      }
      case 1: {
        red(currY, currX, newNy, newNx, num);
        break;
      }
      case 2: {
        break;
      }
      default: {
        break;
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N >> K;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 1; i <= K; i++) {
    cin >> mal[i][0] >> mal[i][1] >> mal[i][2];
    stackArr[mal[i][0]][mal[i][1]].push_back(i);
  }

  int turn = 0;
  bool endFlag = true;
  while (endFlag && turn <= 1000) {
    for (int i = 1; i <= K; i++) {
      int currY = mal[i][0];
      int currX = mal[i][1];
      int dirNum = mal[i][2];

      int ny = currY + dy[dirNum];
      int nx = currX + dx[dirNum];
      if (inRange(ny, nx)) {
        int next = board[ny][nx];
        switch (next) {
          case 0: {  // 흰색
            white(currY, currX, ny, nx, i);
            break;
          }
          case 1: {  // 빨간색
            red(currY, currX, ny, nx, i);
            break;
          }
          case 2: {  // 파란색
            blue(currY, currX, ny, nx, i, dirNum);
            break;
          }
          default:
            break;
        }
      } else {  // 파란색
        blue(currY, currX, ny, nx, i, dirNum);
      };

      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
          if (stackArr[i][j].size() >= 4) {
            endFlag = false;
          }
        }
      }
    }

    turn++;
  }

  if (!endFlag) {
    cout << turn;
  } else {
    cout << -1;
  }

  return 0;
}
