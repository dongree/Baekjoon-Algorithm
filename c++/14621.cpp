#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

char univ[1001];
vector<pair<int, pair<int, int>>> routes;
int parents[1001];

int getParent(int x) {
  if (x == parents[x])
    return x;
  else
    return parents[x] = getParent(parents[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a > b)
    parents[a] = b;
  else if (a < b)
    parents[b] = a;
}

bool sameParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  return a == b;
}

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> univ[i];
    parents[i] = i;
  }

  for (int i = 0; i < M; i++) {
    int u, v, d;
    cin >> u >> v >> d;

    routes.push_back({d, {u, v}});
  }

  sort(routes.begin(), routes.end());

  int cnt = 0;
  int ans = 0;

  for (int i = 0; i < M; i++) {
    int weight = routes[i].first;
    int from = routes[i].second.first;
    int to = routes[i].second.second;

    if (!sameParent(from, to) && univ[from] != univ[to]) {
      unionParent(from, to);
      ans += weight;
      cnt++;
    }

    if (cnt == N - 1) break;
  }

  cout << ((cnt == N - 1) ? ans : -1);

  return 0;
}