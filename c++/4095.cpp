#include <cstring>
#include <iostream>

using namespace std;

int board[1000][1000];
int dp[1000][1000];

int main() {
  freopen("example.txt", "r", stdin);

  while (true) {
    int N, M;
    cin >> N >> M;

    if (N == 0 && M == 0) break;

    memset(dp, 0, sizeof(dp));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cin >> board[i][j];
      }
    }
    int answer = 0;

    for (int i = 0; i < M; i++) {
      dp[0][i] = board[0][i];
      if (dp[0][i]) answer = dp[0][i];
    }

    for (int i = 0; i < N; i++) {
      dp[i][0] = board[i][0];
      if (dp[i][0]) answer = dp[i][0];
    }

    for (int i = 1; i < N; i++) {
      for (int j = 1; j < M; j++) {
        if (board[i][j] == 0) continue;
        dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
        answer = max(answer, dp[i][j]);
      }
    }

    cout << answer << '\n';
  }
  return 0;
}