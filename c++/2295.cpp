#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[1000];
vector<int> sum;

bool binarySearch(int target) {
  int start = 0;
  int end = sum.size() - 1;

  while (start <= end) {
    int mid = (start + end) / 2;

    if (target < sum[mid])
      end = mid - 1;
    else if (target > sum[mid])
      start = mid + 1;
    else
      return true;
  }

  return false;
}

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < N; i++) {
    for (int j = i; j < N; j++) {
      sum.push_back(arr[i] + arr[j]);
    }
  }

  sort(arr, arr + N);
  sort(sum.begin(), sum.end());

  for (int k = N - 1; k >= 0; k--) {
    for (int z = k; z >= 0; z--) {
      int target = arr[k] - arr[z];
      if (binarySearch(target)) {
        cout << arr[k];
        return 0;
      }
    }
  }

  return 0;
}