#include <iostream>

typedef long long ll;

using namespace std;

int arr[100][100];
ll dp[100][100];

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> arr[i][j];
    }
  }

  dp[0][0] = 1;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j] == 0) continue;
      if (dp[i][j] == 0) continue;

      int ny1 = i + arr[i][j];
      int nx1 = j;
      int ny2 = i;
      int nx2 = j + arr[i][j];

      if (0 <= ny1 && ny1 < N) dp[ny1][nx1] += dp[i][j];
      if (0 <= nx2 && nx2 < N) dp[ny2][nx2] += dp[i][j];
    }
  }

  cout << dp[N - 1][N - 1];

  return 0;
}