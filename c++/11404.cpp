#include <climits>
#include <iostream>

#define INF 1e9

using namespace std;

int minCost[101][101];

int main() {
  freopen("example.txt", "r", stdin);
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (i == j)
        minCost[i][j] = 0;
      else
        minCost[i][j] = INF;
    }
  }

  for (int i = 0; i < m; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    if (c < minCost[a][b]) minCost[a][b] = c;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (minCost[i][k] + minCost[k][j] < minCost[i][j]) {
          minCost[i][j] = minCost[i][k] + minCost[k][j];
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (minCost[i][j] >= INF) {
        cout << 0 << ' ';
      } else {
        cout << minCost[i][j] << ' ';
      }
    }
    cout << '\n';
  }

  return 0;
}