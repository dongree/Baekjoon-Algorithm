#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  while (N--) {
    int a;
    cin >> a;
    arr.push_back(a);
  }

  sort(arr.begin(), arr.end(), greater<>());

  int ans = 0;

  for (int i = 0; i < arr.size(); i++) {
    if (i % 3 == 2) continue;
    ans += arr[i];
  }

  cout << ans;

  return 0;
}