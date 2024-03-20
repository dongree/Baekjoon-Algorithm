#include <algorithm>
#include <iostream>

using namespace std;

int arr[100000];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + N);

  int start = 0;
  int end = N - 1;
  int maxMixed = arr[start] + arr[end];
  int result1 = arr[start];
  int result2 = arr[end];

  while (start < end) {
    int mixed = arr[start] + arr[end];
    if (abs(mixed) < abs(maxMixed)) {
      maxMixed = mixed;
      result1 = arr[start];
      result2 = arr[end];
    }
    if (mixed == 0) break;

    if (mixed < 0)
      start++;
    else
      end--;
  }

  cout << result1 << ' ' << result2;

  return 0;
}