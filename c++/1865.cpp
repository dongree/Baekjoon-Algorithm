#include <iostream>
#include <vector>

#define INF 10000000

using namespace std;

struct edge {
  int s, e, t;
};

int N, M, W, S, E, T;

vector<edge> v;
int dist[501];

void bellmanford() {
  dist[1] = 0;
  for (int i = 1; i < N; i++) {
    for (int pos = 0; pos < v.size(); pos++) {
      int from = v[pos].s;
      int to = v[pos].e;
      int cost = v[pos].t;

      if (dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
    }
  }

  for (int pos = 0; pos < v.size(); pos++) {
    int from = v[pos].s;
    int to = v[pos].e;
    int cost = v[pos].t;
    if (dist[from] + cost < dist[to]) {
      cout << "YES\n";
      return;
    }
  }

  cout << "NO\n";
}

void init() {
  v.clear();
  for (int i = 1; i <= N; i++) {
    dist[i] = INF;
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  int tc;
  cin >> tc;

  while (tc--) {
    cin >> N >> M >> W;
    init();
    while (M--) {
      cin >> S >> E >> T;
      v.push_back({S, E, T});
      v.push_back({E, S, T});
    }
    while (W--) {
      cin >> S >> E >> T;
      v.push_back({S, E, -T});
    }

    bellmanford();
  }

  return 0;
}