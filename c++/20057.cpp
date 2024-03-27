// 1시간 10분 소요

#include <iostream>
#include <vector>

using namespace std;

int N;
int dy[4] = {0, 1, 0, -1};
int dx[4] = {-1, 0, 1, 0};
int board[500][500];
vector<int> v;
int answer = 0;

int sandP[9] = {1, 1, 2, 2, 7, 7, 10, 10, 5};

int sandY[4][10] = {
    {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
    {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},
    {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
    {1, 1, 0, 0, 0, 0, -1, -1, -2, -1},
};
int sandX[4][10] = {
    {1, 1, 0, 0, 0, 0, -1, -1, -2, -1},
    {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
    {-1, -1, 0, 0, 0, 0, 1, 1, 2, 1},
    {-1, 1, -2, 2, -1, 1, -1, 1, 0, 0},
};

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

void scatterSand(int y, int x, int dir) {
  int totalSand = board[y][x];

  for (int i = 0; i < 9; i++) {
    int sand = board[y][x] * sandP[i] / 100;
    if (sand > 0) {
      int ny = y + sandY[dir][i];
      int nx = x + sandX[dir][i];
      if (!inRange(ny, nx)) {
        answer += sand;
      } else {
        board[ny][nx] += sand;
      }
      totalSand -= sand;
    }
  }
  int ny = y + sandY[dir][9];
  int nx = x + sandX[dir][9];
  if (!inRange(ny, nx)) {
    answer += totalSand;
  } else {
    board[ny][nx] += totalSand;
  }

  board[y][x] = 0;
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  for (int i = 1; i < N; i++) {
    v.push_back(i);
    v.push_back(i);
  }
  v.push_back(N - 1);

  int sy = N / 2;
  int sx = N / 2;

  for (int i = 0; i < v.size(); i++) {
    int cnt = v[i];
    while (cnt--) {
      sy += dy[i % 4];
      sx += dx[i % 4];
      if (board[sy][sx] != 0) {
        scatterSand(sy, sx, i % 4);
      }
    }
  }

  cout << answer;
  return 0;
}