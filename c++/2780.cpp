#include <iostream>

using namespace std;

int dp[1001][10];

int divide(int n) { return n % 1234567; }

int main() {
  freopen("example.txt", "r", stdin);

  int T;
  cin >> T;

  for (int i = 0; i < 10; i++) {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= 1000; i++) {
    dp[i][0] = divide(dp[i - 1][7]);
    dp[i][1] = divide(dp[i - 1][2] + dp[i - 1][4]);
    dp[i][2] = divide(dp[i - 1][1] + dp[i - 1][3] + dp[i - 1][5]);
    dp[i][3] = divide(dp[i - 1][2] + dp[i - 1][6]);
    dp[i][4] = divide(dp[i - 1][1] + dp[i - 1][5] + dp[i - 1][7]);
    dp[i][5] =
        divide(dp[i - 1][2] + dp[i - 1][4] + dp[i - 1][6] + dp[i - 1][8]);
    dp[i][6] = divide(dp[i - 1][3] + dp[i - 1][5] + dp[i - 1][9]);
    dp[i][7] = divide(dp[i - 1][0] + dp[i - 1][4] + dp[i - 1][8]);
    dp[i][8] = divide(dp[i - 1][5] + dp[i - 1][7] + dp[i - 1][9]);
    dp[i][9] = divide(dp[i - 1][6] + dp[i - 1][8]);
  }

  while (T--) {
    int N;
    cin >> N;

    int cnt = 0;

    for (int i = 0; i < 10; i++) {
      cnt += dp[N][i];
    }

    cout << divide(cnt) << '\n';
  }

  return 0;
}