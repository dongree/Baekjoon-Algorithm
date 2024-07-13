#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int counts[10];

int getTypeCount() {
  int cnt = 0;
  for (int i = 1; i < 10; i++) {
    if (counts[i] != 0) cnt++;
  }

  return cnt;
}

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  int start = 0;
  int end = 0;
  int ans = 0;

  while (end < N) {
    counts[v[end]]++;

    if (getTypeCount() > 2) {
      counts[v[start]]--;
      start++;
    }

    ans = max(ans, end - start + 1);

    end++;
  }

  cout << ans;

  return 0;
}