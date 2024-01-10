#include <algorithm>
#include <iostream>

using namespace std;

int arr[100001][3];
int pre[2][3];
int curr[2][3];

int main() {
  freopen("example.txt", "r", stdin);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
  }

  for (int i = 1; i <= n; i++) {
    curr[0][0] = arr[i][0] + max(pre[0][0], pre[0][1]);
    curr[0][1] = arr[i][1] + max({pre[0][0], pre[0][1], pre[0][2]});
    curr[0][2] = arr[i][2] + max(pre[0][1], pre[0][2]);

    curr[1][0] = arr[i][0] + min(pre[1][0], pre[1][1]);
    curr[1][1] = arr[i][1] + min({pre[1][0], pre[1][1], pre[1][2]});
    curr[1][2] = arr[i][2] + min(pre[1][1], pre[1][2]);

    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) {
        pre[j][k] = curr[j][k];
      }
    }
  }

  int max = curr[0][0];
  int min = curr[1][0];

  for (int i = 1; i < 3; i++) {
    if (max < curr[0][i]) max = curr[0][i];
    if (min > curr[1][i]) min = curr[1][i];
  }

  cout << max << ' ' << min;

  return 0;
}