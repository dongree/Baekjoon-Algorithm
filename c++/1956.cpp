#include <iostream>

#define INF 1e9

using namespace std;

int arr[401][401];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int V, E;
  cin >> V >> E;

  for (int i = 1; i <= V; i++) {
    for (int j = 1; j <= V; j++) {
      arr[i][j] = INF;
    }
  }

  while (E--) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a][b] = c;
  }

  for (int k = 1; k <= V; k++) {
    for (int i = 1; i <= V; i++) {
      for (int j = 1; j <= V; j++) {
        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
      }
    }
  }

  int answer = INF;
  for (int i = 1; i <= V; i++) {
    if (arr[i][i] < answer) answer = arr[i][i];
  }

  cout << ((answer == INF) ? -1 : answer);

  return 0;
}