#include <iostream>

using namespace std;

int board[10][10];
int isVisited[10][10];
int N;

int dy[5] = {0, 0, 1, 0, -1};
int dx[5] = {0, 1, 0, -1, 0};
int result = 1e9;

bool inRnage(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

bool check(int y, int x) {
  for (int i = 0; i < 5; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (isVisited[ny][nx] || !inRnage(ny, nx)) {
      return false;
    }
  }

  return true;
}

void dfs(int n, int cnt, int cost) {
  if (n > N * N) return;

  if (cnt == 3) {
    if (cost < result) result = cost;
    return;
  }

  int y = n / N;
  int x = n % N;
  if (check(y, x)) {
    int temp = cost;
    for (int i = 0; i < 5; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      isVisited[ny][nx] = true;
      temp += board[ny][nx];
    }
    dfs(n + 1, cnt + 1, temp);
    for (int i = 0; i < 5; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      isVisited[ny][nx] = false;
    }
  }

  dfs(n + 1, cnt, cost);
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
    }
  }

  dfs(0, 0, 0);

  cout << result;

  return 0;
}
