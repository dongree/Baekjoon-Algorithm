#include <algorithm>
#include <iostream>

#define INF 1e9

using namespace std;

int arr[501][501];

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i != j) {
        arr[i][j] = INF;
      }
    }
  }

  while (M--) {
    int a, b;
    cin >> a >> b;
    arr[a][b] = 1;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= N; i++) {
    int k = 0;
    for (int j = 1; j <= N; j++) {
      if (arr[i][j] != INF || arr[j][i] != INF) k++;
    }
    if (k == N) ans++;
  }

  cout << ans;

  return 0;
}