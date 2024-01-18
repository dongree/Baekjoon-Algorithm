// 0-1 bfs
#include <deque>
#include <iostream>
#include <string>

using namespace std;

int m, n;
int miro[100][100];
int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};
bool isVisited[100][100];
int crushed[100][100];

bool inRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }

void bfs() {
  deque<pair<int, int>> dq;

  dq.push_back({0, 0});
  isVisited[0][0] = true;

  while (!dq.empty()) {
    int y = dq.front().first;
    int x = dq.front().second;
    dq.pop_front();

    if (y == n - 1 && x == m - 1) {
      cout << crushed[y][x];
      return;
    }

    for (int i = 0; i < 4; i++) {
      int ny = y + dy[i];
      int nx = x + dx[i];

      if (inRange(ny, nx) && !isVisited[ny][nx]) {
        isVisited[ny][nx] = true;
        if (miro[ny][nx] == 0)
          dq.push_front({ny, nx});
        else
          dq.push_back({ny, nx});
        crushed[ny][nx] = crushed[y][x] + miro[ny][nx];
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> m >> n;

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

// dijkstra>, pq
// #include <iostream>
// #include <queue>
// #include <string>
// #include <vector>

// using namespace std;

// int m, n;
// int miro[100][100];
// int dy[4] = {1, 0, -1, 0};
// int dx[4] = {0, 1, 0, -1};
// bool isVisited[100][100];
// int crushed[100][100];

// bool inRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }

// void dijkstra() {
//   priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int,
//   int>>>,
//                  greater<pair<int, pair<int, int>>>>
//       pq;

//   pq.push({0, {0, 0}});
//   isVisited[0][0] = true;

//   while (!pq.empty()) {
//     int cnt = pq.top().first;
//     int y = pq.top().second.first;
//     int x = pq.top().second.second;
//     pq.pop();

//     if (y == n - 1 && x == m - 1) {
//       cout << cnt;
//       return;
//     }

//     for (int i = 0; i < 4; i++) {
//       int ny = y + dy[i];
//       int nx = x + dx[i];

//       if (inRange(ny, nx) && !isVisited[ny][nx]) {
//         isVisited[ny][nx] = true;
//         if (miro[ny][nx] == 0)
//           pq.push({cnt, {ny, nx}});
//         else
//           pq.push({cnt + 1, {ny, nx}});
//       }
//     }
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);
//   cin >> m >> n;

//   for (int i = 0; i < n; i++) {
//     string s;
//     cin >> s;
//     for (int j = 0; j < s.length(); j++) {
//       miro[i][j] = s[j] - '0';
//     }
//   }

//   dijkstra();

//   return 0;
// }