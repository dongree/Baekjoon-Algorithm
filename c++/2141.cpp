#include <algorithm>
#include <iostream>

typedef long long ll;

using namespace std;

vector<pair<int, int>> arr;

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  ll peopleNum = 0;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    arr.push_back({a, b});
    peopleNum += b;
  }

  sort(arr.begin(), arr.end());

  ll sumV = 0;
  for (int i = 0; i < N; i++) {
    sumV += arr[i].second;
    if (sumV >= (peopleNum / 2 + 1)) {
      cout << arr[i].first;
      return 0;
    }
  }

  cout << arr[N - 1].first;

  return 0;
}