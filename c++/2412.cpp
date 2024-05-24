// #include <algorithm>
// #include <iostream>
// #include <map>
// #include <queue>
// #include <vector>

// using namespace std;

// map<pair<int, int>, bool> visited;
// int n, T;

// vector<pair<int, int>> v;

// bool compare(pair<int, int> a, pair<int, int> b) { return a.second <
// b.second; }

// int bfs() {
//   queue<pair<pair<int, int>, int>> q;
//   q.push({{0, 0}, 0});

//   while (!q.empty()) {
//     int y = q.front().first.first;
//     int x = q.front().first.second;
//     int cnt = q.front().second;
//     q.pop();

//     if (x == T) {
//       return cnt;
//     }

//     if (visited[{y, x}]) continue;
//     visited[{y, x}] = true;

//     auto it = lower_bound(v.begin(), v.end(), make_pair(0, x - 2), compare) -
//               v.begin();

//     for (int i = it; i < n && abs(v[i].second - x) <= 2; i++) {
//       int ny = v[i].first;
//       int nx = v[i].second;
//       if (!visited[{ny, nx}] && abs(ny - y) <= 2) {
//         q.push({{ny, nx}, cnt + 1});
//       }
//     }
//   }

//   return -1;
// }

// int main() {
//   freopen("example.txt", "r", stdin);

//   cin >> n >> T;

//   for (int i = 0; i < n; i++) {
//     int y, x;
//     cin >> y >> x;
//     v.push_back({y, x});
//   }

//   sort(v.begin(), v.end(), compare);

//   cout << bfs();

//   return 0;
// }

#include <iostream>
#include <map>
#include <queue>

using namespace std;

map<pair<int, int>, int> dic;
int n, T;

bool inRange(int y, int x) {
  return 0 <= y && y <= 1000000 && 0 <= x && x <= T;
}

int main() {
  cin >> n >> T;

  for (int i = 0; i < n; i++) {
    int y, x;
    cin >> y >> x;
    dic[{y, x}] = 1;
  }

  queue<pair<pair<int, int>, int>> q;
  q.push({{0, 0}, 0});

  while (!q.empty()) {
    int y = q.front().first.first;
    int x = q.front().first.second;
    int cnt = q.front().second;
    q.pop();

    if (x == T) {
      cout << cnt;
      return 0;
    }

    for (int i = -2; i <= 2; i++) {
      for (int j = -2; j <= 2; j++) {
        int ny = y + i;
        int nx = x + j;
        if (inRange(ny, nx) && dic[{ny, nx}] == 1) {
          q.push({{ny, nx}, cnt + 1});
          dic.erase({ny, nx});
        }
      }
    }
  }

  cout << -1;

  return 0;
}