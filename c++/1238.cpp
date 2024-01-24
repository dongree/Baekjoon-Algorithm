// // floyd warshal
// #include <algorithm>
// #include <iostream>

// #define MAX 1000000

// using namespace std;

// int roads[1001][1001];

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);

//   freopen("example.txt", "r", stdin);

//   int N, M, X;
//   cin >> N >> M >> X;

//   for (int i = 1; i <= N; i++) {
//     for (int j = 1; j <= N; j++) {
//       if (i == j) continue;
//       roads[i][j] = MAX;
//     }
//   }

//   for (int i = 0; i < M; i++) {
//     int start, end, t;
//     cin >> start >> end >> t;
//     roads[start][end] = t;
//   }

//   for (int k = 1; k <= N; k++) {
//     for (int i = 1; i <= N; i++) {
//       for (int j = 1; j <= N; j++) {
//         roads[i][j] = min(roads[i][j], roads[i][k] + roads[k][j]);
//       }
//     }
//   }

//   int maxLong = 0;
//   for (int i = 1; i <= N; i++) {
//     maxLong = max(maxLong, roads[i][X] + roads[X][i]);
//   }

//   cout << maxLong;

//   return 0;
// }

// dijkstra
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define MAX 1000000

using namespace std;

vector<pair<int, int>> adj[2][1001];
int minDist[2][1001];
int answer;

void dijkstra(int level, int start) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  pq.push({0, start});
  minDist[level][start] = 0;

  while (!pq.empty()) {
    int weight = pq.top().first;
    int curr = pq.top().second;
    pq.pop();

    if (minDist[level][curr] < weight) continue;
    for (int i = 0; i < adj[level][curr].size(); i++) {
      int next = adj[level][curr][i].second;
      int nextWeight = weight + adj[level][curr][i].first;

      if ((nextWeight) < minDist[level][next]) {
        minDist[level][next] = nextWeight;
        pq.push({nextWeight, next});
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  freopen("example.txt", "r", stdin);

  int N, M, X;
  cin >> N >> M >> X;

  for (int i = 1; i <= N; i++) {
    minDist[0][i] = MAX;
    minDist[1][i] = MAX;
  }

  for (int i = 0; i < M; i++) {
    int start, end, t;
    cin >> start >> end >> t;
    adj[0][start].push_back({t, end});
    adj[1][end].push_back({t, start});
  }

  dijkstra(0, X);
  dijkstra(1, X);

  for (int i = 1; i <= N; i++) {
    if (i == X) continue;
    int dist = minDist[0][i] + minDist[1][i];
    answer = max(answer, dist);
  }

  cout << answer;

  return 0;
}