#include <iostream>

using namespace std;

int dp[101][101];  // dp[i][j] : (i ,j) 위치에 도달했을 때 지나온 최대 칸 수
int arr[101][101];

int main() {
  freopen("example.txt", "r", stdin);

  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }

  dp[1][1] = 1;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      for (int a = 0; a <= i; a++) {
        for (int b = 0; b <= j; b++) {
          if (arr[a][b] < arr[i][j])
            dp[i][j] = max(dp[i][j], dp[a][b] + 1);
          else if (arr[a][b] == arr[i][j])
            dp[i][j] = max(dp[i][j], dp[a][b]);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << dp[i][j] << ' ';
      if (dp[i][j] > ans) ans = dp[i][j];
    }
    cout << '\n';
  }

  cout << ans;

  return 0;
}