#include <iostream>

using namespace std;

int arr[300][300];
int sArr[301][301];

int main() {
  freopen("example.txt", "r", stdin);
  int N, M, K;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      sArr[i][j] = arr[i - 1][j - 1] + sArr[i][j - 1] + sArr[i - 1][j] -
                   sArr[i - 1][j - 1];
    }
  }
  cin >> K;
  while (K--) {
    int i, j, x, y;
    cin >> i >> j >> x >> y;
    cout << sArr[x][y] - sArr[x][j - 1] - sArr[i - 1][y] + sArr[i - 1][j - 1]
         << '\n';
  }

  return 0;
}