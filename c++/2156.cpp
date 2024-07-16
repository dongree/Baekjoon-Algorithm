#include <algorithm>
#include <iostream>

using namespace std;

int wine[10000];
int dp[10001];

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> wine[i];
  }

  dp[1] = wine[0];
  dp[2] = wine[0] + wine[1];

  for (int i = 3; i <= N; i++) {
    dp[i] = max(max(dp[i - 1], dp[i - 2] + wine[i - 1]),
                dp[i - 3] + wine[i - 1] + wine[i - 2]);
  }

  cout << dp[N];

  return 0;
}