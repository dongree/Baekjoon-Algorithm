#include <iostream>

#define INF 1e9

using namespace std;

int arr[201][201];
int ans[201][201];

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i != j) {
        arr[i][j] = INF;
        ans[i][j] = j;
      }
    }
  }

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    arr[a][b] = c;
    arr[b][a] = c;
  }

  for (int k = 1; k <= N; k++) {
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (arr[i][j] > arr[i][k] + arr[k][j]) {
          ans[i][j] = ans[i][k];
          arr[i][j] = arr[i][k] + arr[k][j];
        }
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (i == j)
        cout << '-' << ' ';
      else
        cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }

  return 0;
}