// // 0-1 bfs
// #include <deque>
// #include <iostream>
// #include <string>

// using namespace std;

// int N, M;
// int curX, curY, targetX, targetY;
// int arr[300][300];
// bool isVisited[300][300];

// int dy[4] = {0, 1, 0, -1};
// int dx[4] = {1, 0, -1, 0};

// bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

// bool bfs() {
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < M; j++) {
//       isVisited[i][j] = false;
//     }
//   }

//   deque<pair<int, int>> dq;
//   dq.push_back({curY - 1, curX - 1});
//   isVisited[curY - 1][curX - 1] = true;

//   while (!dq.empty()) {
//     int y = dq.front().first;
//     int x = dq.front().second;
//     dq.pop_front();

//     if (y == targetY - 1 && x == targetX - 1) {
//       return true;
//     }

//     if (arr[y][x] == 1) {
//       arr[y][x] = 0;
//       continue;
//     }

//     for (int i = 0; i < 4; i++) {
//       int ny = y + dy[i];
//       int nx = x + dx[i];
//       if (inRange(ny, nx) && !isVisited[ny][nx]) {
//         isVisited[ny][nx] = true;
//         if (arr[ny][nx] == 1) {
//           dq.push_back({ny, nx});
//         } else {
//           dq.push_front({ny, nx});
//         }
//       }
//     }
//   }

//   return false;
// }

// int main() {
//   freopen("example.txt", "r", stdin);
//   cin >> N >> M;
//   cin >> curY >> curX >> targetY >> targetX;

//   for (int i = 0; i < N; i++) {
//     string s;
//     cin >> s;
//     for (int j = 0; j < M; j++) {
//       arr[i][j] = s[j] - '0';
//     }
//   }

//   int ans = 1;
//   while (!bfs()) {
//     ans++;
//   }

//   cout << ans;

//   return 0;
// }

// bfs
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, M;
int curX, curY, targetX, targetY;
int arr[300][300];
bool isVisited[300][300];

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

bool inRange(int y, int x) { return 0 <= y && y < N && 0 <= x && x < M; }

bool bfs() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      isVisited[i][j] = false;
    }
  }

  queue<pair<int, int>> q;
  q.push({curY - 1, curX - 1});
  isVisited[curY - 1][curX - 1] = true;

  while (!q.empty()) {
    int y = q.front().first;
    int x = q.front().second;
    q.pop();

    if (y == targetY - 1 && x == targetX - 1) {
      return true;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];
      if (inRange(ny, nx) && !isVisited[ny][nx]) {
        isVisited[ny][nx] = true;
        if (arr[ny][nx] == 1) {
          arr[ny][nx] = 0;
        } else {
          q.push({ny, nx});
        }
      }
    }
  }

  return false;
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> M;
  cin >> curY >> curX >> targetY >> targetX;

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < M; j++) {
      arr[i][j] = s[j] - '0';
    }
  }

  int ans = 1;
  while (!bfs()) {
    ans++;
  }

  cout << ans;

  return 0;
}