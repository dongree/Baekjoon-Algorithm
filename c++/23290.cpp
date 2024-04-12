// 2시간 25분 소요

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int M, S;

vector<int> board[5][5];
vector<int> copyBoard[5][5];
int fishSmell[5][5];
int sy, sx;
vector<int> sharkRoute;
vector<int> tempRoute;
int maxFishNum = -1;

int fdy[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int fdx[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

// 상좌하우
int sdy[4] = {-1, 0, 1, 0};
int sdx[4] = {0, -1, 0, 1};

bool inRange(int y, int x) { return 1 <= y && y <= 4 && 1 <= x && x <= 4; }

void moveAllFish() {
  vector<int> temp[5][5];

  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      if (board[i][j].size() == 0) continue;
      for (int a = 0; a < board[i][j].size(); a++) {
        int dir = board[i][j][a];
        bool isMove = false;
        for (int k = 0; k < 8; k++) {
          int ndir = ((dir - k <= 0) ? dir - k + 8 : dir - k);
          int ny = i + fdy[ndir];
          int nx = j + fdx[ndir];
          if (inRange(ny, nx) && !(ny == sy && nx == sx) &&
              fishSmell[ny][nx] == 0) {
            isMove = true;
            temp[ny][nx].push_back(ndir);
            break;
          }
        }
        if (!isMove) {
          temp[i][j].push_back(dir);
        }
      }
    }
  }

  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      board[i][j] = temp[i][j];
    }
  }
}

void dfs(int y, int x, int cnt, int fishNum) {
  if (cnt == 3) {
    if (fishNum > maxFishNum) {
      maxFishNum = fishNum;
      sharkRoute = tempRoute;
    }
    return;
  }
  for (int i = 0; i < 4; i++) {
    int ny = y + sdy[i];
    int nx = x + sdx[i];
    if (inRange(ny, nx)) {
      int nFishNum = fishNum + board[ny][nx].size();
      vector<int> temp = board[ny][nx];
      board[ny][nx].clear();
      tempRoute.push_back(i);
      dfs(ny, nx, cnt + 1, nFishNum);
      tempRoute.pop_back();
      board[ny][nx] = temp;
    }
  }
}

void moveShark() {
  maxFishNum = -1;

  dfs(sy, sx, 0, 0);

  for (int i = 0; i < sharkRoute.size(); i++) {
    sy += sdy[sharkRoute[i]];
    sx += sdx[sharkRoute[i]];

    if (board[sy][sx].size() > 0) {
      board[sy][sx].clear();
      fishSmell[sy][sx] = S;
    }
  }
}

void deleteSmell() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      if (fishSmell[i][j] == S + 2) fishSmell[i][j] = 0;
    }
  }
}

void copyFish() {
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      for (int k = 0; k < copyBoard[i][j].size(); k++) {
        board[i][j].push_back(copyBoard[i][j][k]);
      }
    }
  }

  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      copyBoard[i][j] = board[i][j];
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> M >> S;

  while (M--) {
    int y, x, d;
    cin >> y >> x >> d;
    board[y][x].push_back(d);
    copyBoard[y][x].push_back(d);
  }

  cin >> sy >> sx;

  while (S--) {
    moveAllFish();
    moveShark();
    deleteSmell();
    copyFish();
  }

  int answer = 0;
  for (int i = 1; i <= 4; i++) {
    for (int j = 1; j <= 4; j++) {
      answer += board[i][j].size();
    }
  }

  cout << answer;

  return 0;
}