#include <iostream>

using namespace std;

int arr[100000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int start = 0;
  int end = N - 1;
  int min = abs(arr[start] + arr[end]);
  int answer[2];
  answer[0] = arr[start];
  answer[1] = arr[end];

  while (start < end) {
    int sum = arr[start] + arr[end];
    int now = abs(sum);
    if (now <= min) {
      min = now;
      answer[0] = arr[start];
      answer[1] = arr[end];
    }

    if (sum < 0) {
      start++;
    } else {
      end--;
    }
  }

  cout << answer[0] << ' ' << answer[1];

  return 0;
}