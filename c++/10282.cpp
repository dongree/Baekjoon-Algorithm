#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int dist[10001];

int main() {
  freopen("example.txt", "r", stdin);
  int T;
  cin >> T;

  while (T--) {
    int n, d, c;
    cin >> n >> d >> c;

    for (int i = 1; i <= n; i++) {
      dist[i] = INF;
    }
    vector<pair<int, int>> adjList[10001];
    while (d--) {
      int a, b, s;
      cin >> a >> b >> s;
      adjList[b].push_back({s, a});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        pq;
    pq.push({0, c});
    dist[c] = 0;

    while (!pq.empty()) {
      int node = pq.top().second;
      int weight = pq.top().first;
      pq.pop();

      for (int i = 0; i < adjList[node].size(); i++) {
        int nextNode = adjList[node][i].second;
        int nextWeight = weight + adjList[node][i].first;

        if (dist[nextNode] > nextWeight) {
          dist[nextNode] = nextWeight;
          pq.push({nextWeight, nextNode});
        }
      }
    }

    int cnt = 0;
    int t = 0;
    for (int i = 1; i <= n; i++) {
      if (dist[i] != 1e9) {
        cnt++;
        if (dist[i] > t) t = dist[i];
      }
    }

    cout << cnt << ' ' << t << '\n';
  }

  return 0;
}