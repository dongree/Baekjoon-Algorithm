#include <iostream>

using namespace std;

int dp[41];
bool isVip[41];

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  while (M--) {
    int a;
    cin >> a;
    isVip[a] = true;
  }

  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i <= 40; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  }

  long long result = 1;
  int cnt = 0;

  for (int i = 1; i <= N; i++) {
    if (isVip[i]) {
      result *= dp[cnt];
      cnt = 0;
      continue;
    }
    cnt++;
  }

  cout << result * dp[cnt];

  return 0;
}