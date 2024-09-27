#include <iostream>

using namespace std;

int N, K;
int arr[5000];
bool dp[5000];

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  dp[0] = true;

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (dp[i] && ((j - i) * (1 + abs(arr[i] - arr[j]))) <= K) {
        dp[j] = true;
      };
    }
  }

  cout << (dp[N - 1] ? "YES" : "NO");

  return 0;
}