#include <string.h>

#include <iostream>

#define INF 1e9
#define MAX 16

using namespace std;

int W[MAX][MAX];
int N;
int dp[MAX][1 << MAX];

int dfs(int curr, int visited) {
  if (visited == (1 << N) - 1) {
    if (W[curr][0] == 0)
      return INF;
    else
      return W[curr][0];
  }

  if (dp[curr][visited] != -1) return dp[curr][visited];

  dp[curr][visited] = INF;
  for (int i = 0; i < N; i++) {
    if (W[curr][i] == 0) continue;
    if (visited & (1 << i)) continue;

    dp[curr][visited] =
        min(dp[curr][visited], W[curr][i] + dfs(i, visited | (1 << i)));
  }

  return dp[curr][visited];
}

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> W[i][j];
    }
  }

  memset(dp, -1, sizeof(dp));

  cout << dfs(0, 1);

  return 0;
}