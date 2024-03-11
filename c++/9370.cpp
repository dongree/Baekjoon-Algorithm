// 첫번째 풀이
// #include <algorithm>
// #include <iostream>
// #include <queue>
// #include <vector>

// #define INF 1e9

// using namespace std;

// int dijkstra(int start, int end, int n, vector<pair<int, int>> adjList[]) {
//   priority_queue<pair<int, int>, vector<pair<int, int>>,
//                  greater<pair<int, int>>>
//       pq;
//   int minDist[2001];

//   for (int i = 1; i <= n; i++) {
//     minDist[i] = INF;
//   }

//   minDist[start] = 0;
//   pq.push({0, start});

//   while (!pq.empty()) {
//     int weight = pq.top().first;
//     int node = pq.top().second;
//     pq.pop();

//     for (int i = 0; i < adjList[node].size(); i++) {
//       int nextWeight = weight + adjList[node][i].first;
//       int nextNode = adjList[node][i].second;
//       if (nextWeight < minDist[nextNode]) {
//         minDist[nextNode] = nextWeight;
//         pq.push({nextWeight, nextNode});
//       }
//     }
//   }

//   return ((minDist[end] == INF) ? -INF : minDist[end]);
// };

// int main() {
//   ios_base::sync_with_stdio(0);
//   cin.tie(0);

//   int T;
//   cin >> T;
//   while (T--) {
//     int n, m, t, s, g, h;
//     cin >> n >> m >> t;
//     cin >> s >> g >> h;

//     vector<pair<int, int>> adjList[2001];

//     while (m--) {
//       int a, b, d;
//       cin >> a >> b >> d;
//       adjList[a].push_back({d, b});
//       adjList[b].push_back({d, a});
//     }

//     vector<int> answer;

//     while (t--) {
//       int x;
//       cin >> x;
//       int k = dijkstra(s, x, n, adjList);
//       if (k < 0) continue;

//       int case1 = dijkstra(s, g, n, adjList) + dijkstra(g, h, n, adjList) +
//                   dijkstra(h, x, n, adjList);
//       int case2 = dijkstra(s, h, n, adjList) + dijkstra(h, g, n, adjList) +
//                   dijkstra(g, x, n, adjList);

//       if (min(case1, case2) == k) answer.push_back(x);
//     }

//     sort(answer.begin(), answer.end());

//     for (int i = 0; i < answer.size(); i++) {
//       cout << answer[i] << ' ';
//     }
//     cout << '\n';
//   }

//   return 0;
// }

// 더 효율적인 풀이
#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

vector<pair<int, int>> adjList[2001];
int minDistS[2001];
int minDistG[2001];
int minDistH[2001];

void init() {
  for (int i = 1; i <= 2000; i++) {
    adjList[i].clear();
    minDistS[i] = INF;
    minDistG[i] = INF;
    minDistH[i] = INF;
  }
}

void dijkstra(int start, int minDist[2001]) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;

  minDist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int weight = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    for (int i = 0; i < adjList[node].size(); i++) {
      int nextWeight = weight + adjList[node][i].first;
      int nextNode = adjList[node][i].second;
      if (nextWeight < minDist[nextNode]) {
        minDist[nextNode] = nextWeight;
        pq.push({nextWeight, nextNode});
      }
    }
  }
};

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    init();

    int n, m, t, s, g, h;

    cin >> n >> m >> t;
    cin >> s >> g >> h;

    while (m--) {
      int a, b, d;
      cin >> a >> b >> d;
      adjList[a].push_back({d, b});
      adjList[b].push_back({d, a});
    }

    vector<int> answer;

    dijkstra(s, minDistS);
    dijkstra(g, minDistG);
    dijkstra(h, minDistH);

    while (t--) {
      int x;
      cin >> x;

      if ((minDistS[x] == (minDistS[g] + minDistG[h] + minDistH[x])) ||
          (minDistS[x] == (minDistS[h] + minDistH[g] + minDistG[x]))) {
        answer.push_back(x);
      }
    }

    sort(answer.begin(), answer.end());

    for (int i = 0; i < answer.size(); i++) {
      cout << answer[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}