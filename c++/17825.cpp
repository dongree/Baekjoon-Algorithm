// 2시간 소요

#include <iostream>
#include <vector>

using namespace std;

// dir 0: 아래 방향, 1: 오른쪽 방향
struct loc {
  int y, x, dir;
};

int board[30][15];
int turn[10];
bool isVisited[30][15];
int answer = 0;


void makeBoard() {
  for (int i = 0; i <= 20; i++) {
    board[i][0] = 2 * i;
  }

  board[5][1] = 13;
  board[5][2] = 16;
  board[5][3] = 19;

  board[10][1] = 22;
  board[10][2] = 24;

  board[15][1] = 28;
  board[15][2] = 27;
  board[15][3] = 26;

  for (int j = 4; j <= 7; j++) {
    board[5][j] = 25 + (j - 4) * 5;
    board[10][j - 1] = 25 + (j - 4) * 5;
    board[15][j] = 25 + (j - 4) * 5;
  }
}

bool isAnyPlayer(int y, int x) {
  if (isVisited[y][x]) return true;

  if (board[y][x] == 25) {
    return (isVisited[5][4] || isVisited[10][3] || isVisited[15][4]);
  }

  if (board[y][x] == 30 && x != 0) {
    return (isVisited[5][5] || isVisited[10][4] || isVisited[15][5]);
  }

  if (board[y][x] == 35) {
    return (isVisited[5][6] || isVisited[10][5] || isVisited[15][6]);
  }

  if (board[y][x] == 40) {
    return (isVisited[5][7] || isVisited[10][6] || isVisited[15][7] ||
            isVisited[20][0]);
  }

  return false;
}

void dfs(int idx, vector<loc> v, int score) {
  if (idx == 10) {
    if (score > answer) answer = score;
    return;
  }

  for (int i = 0; i < 4; i++) {
    if (v[i].y == -1 && v[i].x == -1) continue;

    if (v[i].dir == 0) {
      int ny = v[i].y + turn[idx];
      int nx = v[i].x;
      if (isAnyPlayer(ny, nx)) continue;

      if (board[ny][nx] == 0) {  // 도착점에 도착했을 때
        int tempY = v[i].y;
        int tempX = v[i].x;
        v[i].y = -1;
        v[i].x = -1;
        isVisited[tempY][tempX] = false;
        dfs(idx + 1, v, score);
        isVisited[tempY][tempX] = true;
        v[i].y = tempY;
        v[i].x = tempX;
        continue;
      }

      if (board[ny][nx] == 10 || board[ny][nx] == 20 || board[ny][nx] == 30) {
        v[i].dir = 1;
      }

      int tempY = v[i].y;
      v[i].y = ny;
      isVisited[tempY][v[i].x] = false;
      isVisited[ny][nx] = true;
      dfs(idx + 1, v, score + board[ny][nx]);
      v[i].y = tempY;
      isVisited[tempY][v[i].x] = true;
      isVisited[ny][nx] = false;
      if (board[ny][nx] == 10 || board[ny][nx] == 20 || board[ny][nx] == 30) {
        v[i].dir = 0;
      }

    } else {
      int ny = v[i].y;
      int nx = v[i].x + turn[idx];
      if (isAnyPlayer(ny, nx)) continue;

      if (board[ny][nx] == 0) {  // 도착점에 도착했을 때
        int tempY = v[i].y;
        int tempX = v[i].x;
        v[i].y = -1;
        v[i].x = -1;
        isVisited[tempY][tempX] = false;
        dfs(idx + 1, v, score);
        v[i].y = tempY;
        v[i].x = tempX;
        isVisited[tempY][tempX] = true;
        continue;
      }

      int tempX = v[i].x;
      v[i].x = nx;
      isVisited[v[i].y][tempX] = false;
      isVisited[ny][nx] = true;
      dfs(idx + 1, v, score + board[ny][nx]);
      v[i].x = tempX;
      isVisited[v[i].y][tempX] = true;
      isVisited[ny][nx] = false;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  makeBoard();

  for (int i = 0; i < 10; i++) {
    cin >> turn[i];
  }

  vector<loc> v;
  for (int i = 0; i < 4; i++) {
    v.push_back({0, 0, 0});
  }

  dfs(0, v, 0);

  cout << answer;

  return 0;
}