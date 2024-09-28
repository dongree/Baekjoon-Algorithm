// 1:35 start

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

#define INF 1e9

using namespace std;

int N, K;
vector<pair<int, int>> checkpoint;
int dist[501][501];
int dp[501][501];  // dp[n][k] = n번째 체크 포인트까지 k개의 체크 포인트를
                   // 건너뛰었을 때 최소거리

int main() {
  freopen("example.txt", "r", stdin);
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> N >> K;

  checkpoint.push_back({0, 0});
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    checkpoint.push_back({a, b});
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= K; j++) {
      dp[i][j] = INF;
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      dist[i][j] = abs(checkpoint[i].first - checkpoint[j].first) +
                   abs(checkpoint[i].second - checkpoint[j].second);
    }
  }

  dp[1][0] = 0;
  for (int i = 2; i <= N; i++) {
    dp[i][0] = dp[i - 1][0] + dist[i - 1][i];
  };

  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= K; j++) {
      for (int h = 0; h <= K; h++) {
        if (i - 1 - h < 1) continue;
        if (j - h < 0) continue;
        dp[i][j] = min(dp[i][j], dp[i - 1 - h][j - h] + dist[i - 1 - h][i]);
      }
    }
  }
  int result = INF;
  for (int i = 0; i <= K; i++) {
    result = min(result, dp[N][i]);
  };

  cout << result;
}