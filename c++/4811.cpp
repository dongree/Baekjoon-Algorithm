#include <iostream>

typedef long long ll;

using namespace std;

ll dp[31][31];

int main() {
  freopen("example.txt", "r", stdin);

  for (int w = 1; w <= 30; w++) {
    for (int h = 0; h <= w; h++) {
      if (h == 0)
        dp[w][h] = 1;
      else
        dp[w][h] = dp[w - 1][h] + dp[w][h - 1];
    }
  }

  while (true) {
    int N;
    cin >> N;

    if (N == 0) break;

    cout << dp[N][N] << '\n';
  }

  return 0;
}
