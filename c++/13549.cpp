// dijkstra
// #include <iostream>
// #include <queue>
// #include <vector>

// #define MAX 100000

// using namespace std;

// bool isVisited[100001];

// int n, k;

// void dijkstra() {
//   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//   pq.push({0, n});

//   while (!pq.empty()) {
//     int cnt = pq.top().first;
//     int loc = pq.top().second;
//     pq.pop();

//     if (isVisited[loc]) continue;
//     isVisited[loc] = true;

//     if (loc == k) {
//       cout << cnt;
//       return;
//     }

//     if (loc * 2 <= MAX) {
//       pq.push({cnt, loc * 2});
//     }

//     if (loc + 1 <= MAX) {
//       pq.push({cnt + 1, loc + 1});
//     }

//     if (0 <= loc - 1) {
//       pq.push({cnt + 1, loc - 1});
//     }
//   }
// }

// int main() {
//   freopen("example.txt", "r", stdin);
//   cin >> n >> k;

//   dijkstra();
//   return 0;
// }

// 0-1 bfs
#include <deque>
#include <iostream>

#define MAX 100000

using namespace std;

bool isVisited[100001];

int n, k;
int answer;

void bfs() {
  deque<pair<int, int>> dq;
  dq.push_back({0, n});

  while (!dq.empty()) {
    int cnt = dq.front().first;
    int loc = dq.front().second;
    dq.pop_front();

    if (isVisited[loc]) continue;
    isVisited[loc] = true;

    if (loc == k) {
      cout << cnt;
      return;
    }

    if (loc * 2 <= MAX) {
      dq.push_front({cnt, loc * 2});
    }

    if (loc + 1 <= MAX) {
      dq.push_back({cnt + 1, loc + 1});
    }

    if (0 <= loc - 1) {
      dq.push_back({cnt + 1, loc - 1});
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> n >> k;

  bfs();
  return 0;
}