#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  while (N--) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  int i = 0;
  int j = v.size() - 1;
  int ans = 0;

  while (i < j) {
    int k = min(v[i], v[j]) * (j - i - 1);
    ans = max(k, ans);

    if (v[i] < v[j])
      i++;
    else
      j--;
  }

  cout << ans;

  return 0;
}