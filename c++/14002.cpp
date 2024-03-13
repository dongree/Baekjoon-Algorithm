#include <iostream>
#include <vector>

using namespace std;

int A[1000];
int dp[1000][2];

int main() {
  freopen("example.txt", "r", stdin);

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  for (int i = 0; i < N; i++) {
    int k = 0;
    int ki = -1;
    for (int j = 0; j < i; j++) {
      if (A[j] < A[i] && k < dp[j][0]) {
        k = dp[j][0];
        ki = j;
      }
    }
    dp[i][0] = k + 1;
    dp[i][1] = ki;
  }

  int maxL = 0;
  int maxI = 0;

  for (int i = 0; i < N; i++) {
    if (maxL < dp[i][0]) {
      maxL = dp[i][0];
      maxI = i;
    }
  }

  vector<int> v;

  while (maxI != -1) {
    v.push_back(A[maxI]);
    maxI = dp[maxI][1];
  }

  cout << maxL << '\n';

  for (int i = v.size() - 1; i >= 0; i--) {
    cout << v[i] << ' ';
  }

  return 0;
}