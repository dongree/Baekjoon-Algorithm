#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

vector<pair<int, int>> adjList[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>
    pq;
int dist[1001];
int cnt[1001];
int n, m;
int preNode[1001];

void dijkstra(int start, int end) {
  pq.push({0, start});
  dist[start] = 0;
  cnt[start] = 1;

  while (!pq.empty()) {
    int cost = pq.top().first;
    int node = pq.top().second;
    pq.pop();

    if (dist[node] < cost) continue;

    for (int i = 0; i < adjList[node].size(); i++) {
      int nextCost = cost + adjList[node][i].first;
      int nextNode = adjList[node][i].second;
      if (nextCost < dist[nextNode]) {
        dist[nextNode] = nextCost;
        cnt[nextNode] = cnt[node] + 1;
        preNode[nextNode] = node;
        pq.push({nextCost, nextNode});
      }
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> n >> m;

  while (m--) {
    int a, b, cost;
    cin >> a >> b >> cost;
    adjList[a].push_back({cost, b});
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }

  int start, end;
  cin >> start >> end;
  dijkstra(start, end);

  cout << dist[end] << '\n';
  cout << cnt[end] << '\n';

  vector<int> v;

  int k = end;
  while (k != 0) {
    v.push_back(k);
    k = preNode[k];
  }

  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << ' ';
  }

  return 0;
}