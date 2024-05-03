#include <iostream>

#define INF 1e9;

using namespace std;

int itemN[101];
int dist[101][101];

int main() {
  freopen("example.txt", "r", stdin);
  int n, m, r;
  cin >> n >> m >> r;

  for (int i = 1; i <= n; i++) {
    cin >> itemN[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      dist[i][j] = INF;
    }
  }

  while (r--) {
    int a, b, l;
    cin >> a >> b >> l;

    dist[a][b] = l;
    dist[b][a] = l;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }

  int ans = 0;

  for (int i = 1; i <= n; i++) {
    int v = 0;
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] <= m) v += itemN[j];
    }
    if (v > ans) ans = v;
  }

  cout << ans;

  return 0;
}