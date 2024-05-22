#include <iostream>
#include <queue>
#include <vector>

typedef long long ll;

#define INF 1e9

using namespace std;

vector<pair<int, int>> adjList[2000];

int N, M;
ll dist[2000];
void dijkstra(int start) {
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;
  pq.push({0, start});
  dist[start] = 0;

  while (!pq.empty()) {
    ll cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (dist[node] < cost) continue;

    for (int i = 0; i < adjList[node].size(); i++) {
      ll nextCost = cost + adjList[node][i].first;
      int nextNode = adjList[node][i].second;

      if (dist[nextNode] > nextCost) {
        dist[nextNode] = nextCost;
        pq.push({nextCost, nextNode});
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
  }

  while (M--) {
    int a, b, cost;
    cin >> a >> b >> cost;
    adjList[a].push_back({cost, b});
  }

  int start, end;
  cin >> start >> end;

  dijkstra(start);

  cout << dist[end];

  return 0;
}