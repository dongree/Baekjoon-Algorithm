#include <algorithm>
#include <iostream>

#define INF 1e9

using namespace std;

int cost[1001][3];
int answer = INF;

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> cost[i][j];
    }
  }

  for (int start = 0; start < 3; start++) {
    int dp[1001][3];
    for (int j = 0; j < 3; j++) {
      if (start == j)
        dp[1][j] = cost[1][j];
      else
        dp[1][j] = INF;
    }

    for (int i = 2; i <= N; i++) {
      dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
      dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
      dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
    }

    for (int j = 0; j < 3; j++) {
      if (start == j) continue;
      answer = min(answer, dp[N][j]);
    }
  }

  cout << answer;

  return 0;
}