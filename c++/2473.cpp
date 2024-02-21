#include <algorithm>
#include <iostream>

using namespace std;

long long arr[5000];
long long N;
long long minVal = 1e18;
long long a, b, c;

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + N);

  for (int start = 0; start < N - 2; start++) {
    int mid = start + 1;
    int end = N - 1;

    while (mid < end) {
      long long sum = arr[start] + arr[mid] + arr[end];
      if (abs(sum) < minVal) {
        minVal = abs(sum);
        a = arr[start];
        b = arr[mid];
        c = arr[end];
      }

      if (sum < 0)
        mid++;
      else
        end--;
    }
  }

  cout << a << ' ' << b << ' ' << c;

  return 0;
}