#include <algorithm>
#include <iostream>

using namespace std;

int memories[101];
int costs[101];
int dp[101][10001];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    cin >> memories[i];
  }

  int sum = 0;
  for (int i = 1; i <= N; i++) {
    cin >> costs[i];
    sum += costs[i];
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= sum; j++) {
      if (j < costs[i])
        dp[i][j] = dp[i - 1][j];
      else
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - costs[i]] + memories[i]);
    }
  }

  for (int j = 0; j <= sum; j++) {
    if (dp[N][j] >= M) {
      cout << j;
      break;
    }
  }

  return 0;
}