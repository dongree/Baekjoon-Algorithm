#include <iostream>

using namespace std;

int arr[1000];
int dp[1000];  // dp[i] : i를 포함하는 감소 부분 수열의 합

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  dp[0] = arr[0];

  for (int i = 1; i < N; i++) {
    int k = 0;
    for (int j = 0; j < i; j++) {
      if (arr[i] < arr[j] && k < dp[j]) {
        k = dp[j];
      }
    }

    dp[i] = arr[i] + k;
  }

  int result = 0;

  for (int i = 0; i < N; i++) {
    if (result < dp[i]) result = dp[i];
  }

  cout << result;

  return 0;
}