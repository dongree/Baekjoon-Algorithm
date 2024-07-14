#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int dp[101][101][101];

int main() {
  freopen("example.txt", "r", stdin);
  string a, b, c;
  cin >> a >> b >> c;

  int n = a.length();
  int m = b.length();
  int k = c.length();

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int l = 1; l <= k; l++) {
        if (a[i - 1] == b[j - 1] && b[j - 1] == c[l - 1]) {
          dp[i][j][l] = dp[i - 1][j - 1][l - 1] + 1;
        } else {
          dp[i][j][l] =
              max(max(dp[i - 1][j][l], dp[i][j - 1][l]), dp[i][j][l - 1]);
        }
      }
    }
  }

  cout << dp[n][m][k];

  return 0;
}