#include <algorithm>
#include <iostream>

using namespace std;

int arr[200001];
int countingArr[100001];

int main() {
  freopen("example.txt", "r", stdin);
  int N, K;
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int i = 0;
  int j = 0;
  int ans = 1;
  countingArr[arr[i]] = 1;

  while (j < N && i <= j) {
    if (j + 1 < N && countingArr[arr[j + 1]] < K) {
      countingArr[arr[j + 1]]++;
      j++;
    } else {
      if (i == j)
        j++;
      else
        countingArr[arr[i]]--;
      i++;
    }

    ans = max(ans, j - i + 1);
  }

  cout << ans;

  return 0;
}