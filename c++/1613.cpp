#include <iostream>

using namespace std;

int arr[401][401];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  while (k--) {
    int a, b;
    cin >> a >> b;
    arr[a][b] = -1;
    arr[b][a] = 1;
  }

  for (int m = 1; m <= n; m++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (arr[i][j] == 0 && arr[i][m] == -1 && arr[m][j] == -1) {
          arr[i][j] = -1;
          arr[j][i] = 1;
        }
      }
    }
  }

  int s;
  cin >> s;
  while (s--) {
    int a, b;
    cin >> a >> b;
    cout << arr[a][b] << '\n';
  }

  return 0;
}