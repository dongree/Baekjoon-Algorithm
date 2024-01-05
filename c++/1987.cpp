#include <iostream>
#include <string>

using namespace std;

int r, c;
int board[20][20];
bool visited[26];
int answer = 1;
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) { return 0 <= y && y < r && 0 <= x && x < c; }

void dfs(int y, int x, int cnt) {
  if (cnt > answer) answer = cnt;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i];
    int nx = x + dx[i];
    if (inRange(ny, nx) && !visited[board[ny][nx] - 'A']) {
      visited[board[ny][nx] - 'A'] = true;
      dfs(ny, nx, cnt + 1);
      visited[board[ny][nx] - 'A'] = false;
    }
  }
}

int main() {
  // freopen("example.txt", "r", stdin);

  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < c; j++) {
      board[i][j] = s[j];
    }
  }

  visited[board[0][0] - 'A'] = true;
  dfs(0, 0, 1);

  cout << answer;

  return 0;
}
