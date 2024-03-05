#include <iostream>
#include <queue>
#include <vector>

#define INF 2000000000

using namespace std;

vector<pair<int, int>> adjList[801];

int N, E;

int dijkstra(int start, int end) {
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  int minDist[801];

  for (int i = 1; i <= N; i++) {
    minDist[i] = INF;
  }
  minDist[start] = 0;
  pq.push({0, start});

  while (!pq.empty()) {
    int currWeight = pq.top().first;
    int currNode = pq.top().second;
    pq.pop();

    if (minDist[currNode] < currWeight) continue;
    for (int i = 0; i < adjList[currNode].size(); i++) {
      int nextWeight = currWeight + adjList[currNode][i].first;
      int nextNode = adjList[currNode][i].second;

      if (nextWeight < minDist[nextNode]) {
        minDist[nextNode] = nextWeight;
        pq.push({nextWeight, nextNode});
      }
    }
  }
  if (minDist[end] == INF) return -INF;
  return minDist[end];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);
  cin >> N >> E;

  for (int i = 0; i < E; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    adjList[a].push_back({c, b});
    adjList[b].push_back({c, a});
  }

  int v1, v2;
  cin >> v1 >> v2;

  int candidate1 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
  int candidate2 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);

  if (candidate1 > candidate2)
    cout << ((candidate2 < 0) ? -1 : candidate2);
  else
    cout << ((candidate1 < 0) ? -1 : candidate1);

  return 0;
}