#include <iostream>

using namespace std;

typedef long long ll;

ll dp[65][10];  // dp[i][j] : i번째 자릿수의 값이 j일때 줄어들지 않는 수의 개수

int main() {
  freopen("example.txt", "r", stdin);
  int T;
  cin >> T;

  for (int j = 0; j < 10; j++) {
    dp[1][j] = 1;
  }

  for (int i = 2; i < 65; i++) {
    for (int j = 0; j < 10; j++) {
      for (int k = j; k < 10; k++) {
        dp[i][j] += dp[i - 1][k];
      }
    }
  }

  while (T--) {
    int n;
    cin >> n;

    ll result = 0;
    for (int j = 0; j < 10; j++) {
      result += dp[n][j];
    }
    cout << result << '\n';
  }

  return 0;
}