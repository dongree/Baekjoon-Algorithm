#include <iostream>

using namespace std;

int arr[200][200];
int ps[201][201];
int ans = -1e9;

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      ps[i][j] =
          arr[i - 1][j - 1] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1];
    }
  }

  for (int y1 = 1; y1 <= N; y1++) {
    for (int x1 = 1; x1 <= M; x1++) {
      for (int y2 = y1; y2 <= N; y2++) {
        for (int x2 = x1; x2 <= M; x2++) {
          int k =
              ps[y2][x2] - ps[y2][x1 - 1] - ps[y1 - 1][x2] + ps[y1 - 1][x1 - 1];
          ans = max(ans, k);
        }
      }
    }
  }

  cout << ans;

  return 0;
}