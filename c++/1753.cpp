#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

vector<pair<int, int>> adjList[20001];
bool isVisited[20001];
int minDist[20001];

void dijkstra(int start) {
  minDist[start] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  pq.push({0, start});

  while (!pq.empty()) {
    int weight = pq.top().first;
    int current = pq.top().second;

    pq.pop();

    if (minDist[current] < weight) continue;
    for (int i = 0; i < adjList[current].size(); i++) {
      int nextWeight = weight + adjList[current][i].first;
      int next = adjList[current][i].second;
      if (nextWeight < minDist[next]) {
        minDist[next] = nextWeight;
        pq.push({nextWeight, next});
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int V, E, K;

  cin >> V >> E >> K;

  for (int i = 0; i < E; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    adjList[u].push_back({w, v});
  }

  for (int i = 1; i <= V; i++) {
    minDist[i] = INT_MAX;
  }

  dijkstra(K);

  for (int i = 1; i <= V; i++) {
    if (minDist[i] == INT_MAX)
      cout << "INF" << '\n';
    else
      cout << minDist[i] << '\n';
  }

  return 0;
}