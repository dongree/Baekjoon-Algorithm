#include <iostream>

using namespace std;

int arr[2001];
int dp[2001][2001];

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i <= N; i++) {
    dp[i][i] = 1;
    if (i + 1 <= N && arr[i] == arr[i + 1]) dp[i][i + 1] = 1;
  }

  for (int diff = 2; diff < N; diff++) {
    for (int i = 1; i + diff <= N; i++) {
      int j = i + diff;
      if (arr[i] == arr[j] && dp[i + 1][j - 1]) dp[i][j] = 1;
    }
  }

  int M;
  cin >> M;

  while (M--) {
    int a, b;
    cin >> a >> b;
    cout << dp[a][b] << '\n';
  }

  return 0;
}