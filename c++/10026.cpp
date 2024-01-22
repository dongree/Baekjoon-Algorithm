#include <iostream>
#include <string>

using namespace std;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

int N;
int cnt = 0;
int picture[100][100];
bool isVisited[100][100];

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      isVisited[i][j] = false;
      cnt = 0;
    }
  }
}

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

void dfs(int y, int x) {
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (inRange(ny, nx) && !isVisited[ny][nx] &&
        picture[y][x] == picture[ny][nx]) {
      isVisited[ny][nx] = true;
      dfs(ny, nx);
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < N; j++) {
      picture[i][j] = s[j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!isVisited[i][j]) {
        isVisited[i][j] = true;
        cnt++;
        dfs(i, j);
      }
    }
  }

  cout << cnt << ' ';
  init();

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (picture[i][j] == 'G') {
        picture[i][j] = 'R';
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (!isVisited[i][j]) {
        isVisited[i][j] = true;
        cnt++;
        dfs(i, j);
      }
    }
  }

  cout << cnt;

  return 0;
}