#include <deque>
#include <iostream>
#include <string>

using namespace std;

int n;
int miro[50][50];
bool isVisited[50][50];
int blacked[50][50];

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

bool inRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < n; }

void bfs() {
  deque<pair<int, int>> dq;
  dq.push_back({0, 0});
  isVisited[0][0] = true;

  while (!dq.empty()) {
    int y = dq.front().first;
    int x = dq.front().second;
    dq.pop_front();

    if (y == n - 1 && x == n - 1) {
      cout << blacked[y][x];
      return;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (inRange(ny, nx) && !isVisited[ny][nx]) {
        isVisited[ny][nx] = true;
        if (miro[ny][nx] == 1) {
          dq.push_front({ny, nx});
          blacked[ny][nx] = blacked[y][x];
        } else {
          dq.push_back({ny, nx});
          blacked[ny][nx] = blacked[y][x] + 1;
        }
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> n;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < s.length(); j++) {
      miro[i][j] = s[j] - '0';
    }
  }

  bfs();

  return 0;
}
