#include <iostream>

using namespace std;

int arr[100000];

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  int start = 0;
  int end = 0;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (start < arr[i]) start = arr[i];
    end += arr[i];
  }

  while (start <= end) {
    int mid = (start + end) / 2;

    int sum = 0;
    int cnt = 1;
    for (int i = 0; i < N; i++) {
      if (sum + arr[i] > mid) {
        sum = 0;
        cnt++;
      }
      sum += arr[i];
    }

    if (cnt <= M) {
      end = mid - 1;
    } else {
      start = mid + 1;
    }
  }

  cout << start;

  return 0;
}