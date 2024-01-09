#include <iostream>

using namespace std;

int dp[100001] = {0, 1, 1, 2, 2, 1, 2, 1};
int coins[4] = {1, 2, 5, 7};

int main() {
  freopen("example.txt", "r", stdin);
  int n;
  cin >> n;

  for (int i = 8; i <= n; i++) {
    int min = dp[i - coins[0]];
    for (int j = 1; j < 4; j++) {
      if (dp[i - coins[j]] < min) min = dp[i - coins[j]];
    }
    dp[i] = min + 1;
  }

  cout << dp[n];

  return 0;
}