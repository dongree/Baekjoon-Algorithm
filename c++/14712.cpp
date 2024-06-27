#include <iostream>

using namespace std;

bool isVisited[25][25];

int N, M;
int cnt = 0;

bool check(int y, int x) {
  return y > 0 && x > 0 && isVisited[y - 1][x - 1] && isVisited[y - 1][x] &&
         isVisited[y][x - 1];
}

void dfs(int n) {
  if (n == N * M) {
    cnt++;
    return;
  }

  int y = n / M;
  int x = n % M;

  if (!check(y, x)) {
    isVisited[y][x] = true;
    dfs(n + 1);
    isVisited[y][x] = false;
  }

  dfs(n + 1);
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> M;

  dfs(0);

  cout << cnt;
  return 0;
}