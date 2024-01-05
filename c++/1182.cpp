#include <iostream>
#include <vector>

using namespace std;

int n, s, answer;
vector<int> v;

void dfs(int sum, int idx) {
  if (idx != 0 && sum == s) answer++;
  for (int i = idx; i < n; i++) {
    sum += v[i];
    dfs(sum, i + 1);
    sum -= v[i];
  }
}

int main() {
  // freopen("example.txt", "r", stdin);

  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  dfs(0, 0);
  cout << answer;

  return 0;
}
