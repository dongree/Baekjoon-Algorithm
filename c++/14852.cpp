#include <iostream>

typedef long long ll;

using namespace std;

ll dp[10000001];

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  dp[0] = 1;
  dp[1] = 2;
  dp[2] = 7;

  ll sum = 0;

  for (int i = 3; i <= N; i++) {
    sum = (sum + dp[i - 3] * 2) % 1000000007;
    dp[i] = (dp[i - 1] * 2 + dp[i - 2] * 3 + sum) % 1000000007;
  }

  cout << dp[N];

  return 0;
}