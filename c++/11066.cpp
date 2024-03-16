#include <algorithm>
#include <iostream>

#define INF 1e9

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);
  int T;
  cin >> T;

  while (T--) {
    int K;
    cin >> K;

    int sums[501] = {0};
    int dp[501][501] = {0};

    for (int i = 0; i < K; i++) {
      int a;
      cin >> a;
      sums[i + 1] = sums[i] + a;
    }

    for (int gap = 1; gap < K; gap++) {
      for (int start = 1; start <= K - gap; start++) {
        int end = start + gap;
        dp[start][end] = INF;
        for (int k = start; k < end; k++) {
          dp[start][end] = min(dp[start][end], dp[start][k] + dp[k + 1][end] +
                                                   sums[end] - sums[start - 1]);
        }
      }
    }

    cout << dp[1][K] << '\n';
  }

  return 0;
}