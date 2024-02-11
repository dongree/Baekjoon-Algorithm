#include <iostream>
#include <queue>

using namespace std;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, -1, 0, 1};

int N;
int space[20][20];
bool isVisited[20][20];
int sharkSize = 2;
int cnt = 0;
int startY, startX;
bool eat = false;
int answer = 0;

void init() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      isVisited[i][j] = false;
    }
  }
}

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

void bfs(int a, int b) {
  queue<pair<pair<int, int>, int>> q;
  q.push({{a, b}, 0});
  isVisited[a][b] = true;
  int temp = 0;

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int t = q.front().second;
    q.pop();

    if (0 < space[y][x] && space[y][x] < sharkSize && temp == t) {
      if ((startY > y) || (startY == y && startX > x)) {
        startY = y;
        startX = x;
        continue;
      }
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (inRange(ny, nx) && !isVisited[ny][nx] && space[ny][nx] <= sharkSize) {
        if (0 < space[ny][nx] && space[ny][nx] < sharkSize && !eat) {
          eat = true;
          startY = ny;
          startX = nx;
          temp = t + 1;
          answer += temp;
        } else {
          isVisited[ny][nx] = true;
          q.push({{ny, nx}, t + 1});
        }
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> space[i][j];
      if (space[i][j] == 9) {
        startY = i;
        startX = j;
        space[i][j] = 0;
      }
    }
  }

  while (true) {
    init();
    bfs(startY, startX);
    if (eat) {
      eat = false;
      cnt++;
      space[startY][startX] = 0;
      if (cnt == sharkSize) {
        sharkSize++;
        cnt = 0;
      }
    } else {
      break;
    }
  }

  cout << answer;

  return 0;
}