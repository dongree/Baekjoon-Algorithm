#include <iostream>
#include <vector>

using namespace std;

int arr[1000000];
vector<int> lis;

int binarySearch(int start, int end, int target) {
  while (start < end) {
    int mid = (start + end) / 2;

    if (lis[mid] < target) {
      start = mid + 1;
    } else {
      end = mid;
    }
  }
  return end;
}

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  lis.push_back(arr[0]);

  for (int i = 1; i < N; i++) {
    if (lis.back() < arr[i]) {
      lis.push_back(arr[i]);
    } else {
      int idx = binarySearch(0, lis.size() - 1, arr[i]);
      lis[idx] = arr[i];
    }
  }

  cout << lis.size();
  return 0;
}