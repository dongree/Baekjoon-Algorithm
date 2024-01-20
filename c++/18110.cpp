#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
  freopen("example.txt", "r", stdin);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  if (n == 0) {
    cout << 0;
  } else {
    int excludedNum = round(n * 0.15);
    float sum = 0;
    for (int i = excludedNum; i < n - excludedNum; i++) {
      sum += v[i];
    }
    int answer = round(sum / (n - 2 * excludedNum));
    cout << answer;
  }

  return 0;
}