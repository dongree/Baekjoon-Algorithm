#include <iostream>

using namespace std;

int n, m;
int arr[1025][1025];
int dp[1025][1025];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
      dp[i][j] = arr[i][j] + dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
    }
  }

  for (int i = 0; i < m; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int ans =
        dp[x2][y2] - (dp[x2][y1 - 1] + dp[x1 - 1][y2]) + dp[x1 - 1][y1 - 1];
    cout << ans << "\n";
  }

  return 0;
}