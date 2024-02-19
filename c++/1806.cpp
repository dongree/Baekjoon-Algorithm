#include <algorithm>
#include <iostream>

using namespace std;

int arr[100000];

int main() {
  freopen("example.txt", "r", stdin);
  int N, S;
  cin >> N >> S;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int start = 0;
  int end = 0;

  int sum = arr[0];
  int answer = 0;

  while (start <= end && end < N) {
    if (sum >= S) {
      if (answer == 0)
        answer = end - start + 1;
      else
        answer = min(answer, end - start + 1);
      sum -= arr[start++];
    } else {
      sum += arr[++end];
    }
  }

  cout << answer;
  return 0;
}