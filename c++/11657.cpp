#include <iostream>
#include <vector>

#define INF 100000000000

using namespace std;

struct edge {
  int a, b, c;
};

int N, M;
vector<edge> edges;
long long dist[501];

bool bellmanford(int start) {
  dist[start] = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < edges.size(); j++) {
      int from = edges[j].a;
      int to = edges[j].b;
      int cost = edges[j].c;

      if (dist[from] != INF && dist[from] + cost < dist[to]) {
        dist[to] = dist[from] + cost;
        if (i == N - 1) return true;
      }
    }
  }
  return false;
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
  }

  while (M--) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({a, b, c});
  }

  if (bellmanford(1)) {
    cout << -1;
  } else {
    for (int i = 2; i <= N; i++) {
      if (dist[i] == INF)
        cout << -1;
      else
        cout << dist[i];
      cout << '\n';
    }
  }

  return 0;
}