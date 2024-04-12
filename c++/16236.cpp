// #include <iostream>
// #include <queue>

// using namespace std;

// int dy[4] = {-1, 0, 1, 0};
// int dx[4] = {0, -1, 0, 1};

// int N;
// int space[20][20];
// bool isVisited[20][20];
// int sharkSize = 2;
// int cnt = 0;
// int startY, startX;
// bool eat = false;
// int answer = 0;

// void init() {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       isVisited[i][j] = false;
//     }
//   }
// }

// bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

// void bfs(int a, int b) {
//   queue<pair<pair<int, int>, int>> q;
//   q.push({{a, b}, 0});
//   isVisited[a][b] = true;
//   int temp = 0;

//   while (!q.empty()) {
//     int y = q.front().first.first;
//     int x = q.front().first.second;
//     int t = q.front().second;
//     q.pop();

//     if (0 < space[y][x] && space[y][x] < sharkSize && temp == t) {
//       if ((startY > y) || (startY == y && startX > x)) {
//         startY = y;
//         startX = x;
//         continue;
//       }
//     }

//     for (int i = 0; i < 4; i++) {
//       int ny = y + dy[i];
//       int nx = x + dx[i];

//       if (inRange(ny, nx) && !isVisited[ny][nx] && space[ny][nx] <=
//       sharkSize) {
//         if (0 < space[ny][nx] && space[ny][nx] < sharkSize && !eat) {
//           eat = true;
//           startY = ny;
//           startX = nx;
//           temp = t + 1;
//           answer += temp;
//         } else {
//           isVisited[ny][nx] = true;
//           q.push({{ny, nx}, t + 1});
//         }
//       }
//     }
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);

//   cin >> N;

//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       cin >> space[i][j];
//       if (space[i][j] == 9) {
//         startY = i;
//         startX = j;
//         space[i][j] = 0;
//       }
//     }
//   }

//   while (true) {
//     init();
//     bfs(startY, startX);
//     if (eat) {
//       eat = false;
//       cnt++;
//       space[startY][startX] = 0;
//       if (cnt == sharkSize) {
//         sharkSize++;
//         cnt = 0;
//       }
//     } else {
//       break;
//     }
//   }

//   cout << answer;

//   return 0;
// }

// my new solution
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 20

using namespace std;

int N;
int board[MAX][MAX];
int dist[MAX][MAX];
int sy, sx;
int sharkSize = 2;
int cnt = 0;
int t = 0;

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < N; }

bool compare(pair<int, int> A, pair<int, int> B) {
  int ay = A.first;
  int ax = A.second;
  int by = B.first;
  int bx = B.second;

  if (dist[ay][ax] == dist[by][bx]) {
    if (ay == by) {
      return ax < bx;
    }
    return ay < by;
  }

  return dist[ay][ax] < dist[by][bx];
}

bool eatFish() {
  queue<pair<int, int>> q;
  memset(dist, -1, sizeof(dist));

  q.push({sy, sx});
  dist[sy][sx] = 0;

  vector<pair<int, int>> v;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    if (0 < board[y][x] && board[y][x] < sharkSize) {
      v.push_back({y, x});
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (inRange(ny, nx) && dist[ny][nx] == -1 &&
          (0 <= board[ny][nx] && board[ny][nx] <= sharkSize)) {
        dist[ny][nx] = dist[y][x] + 1;
        q.push({ny, nx});
      }
    }
  }

  if (v.size() == 0) return false;

  sort(v.begin(), v.end(), compare);

  sy = v[0].first;
  sx = v[0].second;
  t += dist[sy][sx];
  cnt++;
  if (cnt == sharkSize) {
    sharkSize++;
    cnt = 0;
  }
  board[sy][sx] = 0;

  return true;
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> board[i][j];
      if (board[i][j] == 9) {
        sy = i;
        sx = j;
        board[i][j] = 0;
      }
    }
  }

  while (true) {
    if (!eatFish()) break;
  }

  cout << t;

  return 0;
}