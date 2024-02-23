#include <algorithm>
#include <iostream>

using namespace std;

int arr[1000];
int dp[1000];

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    int k = 0;
    for (int j = 0; j < i; j++) {
      if (arr[j] < arr[i]) k = max(k, dp[j]);
    }
    dp[i] = arr[i] + k;
  }

  int answer = 0;
  for (int i = 0; i < N; i++) {
    answer = max(answer, dp[i]);
  }
  cout << answer;

  return 0;
}