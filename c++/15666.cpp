#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int n, m;

int arr[8];
set<vector<int>> answer;
vector<int> v;

void dfs(int idx, int cnt) {
  if (cnt == m) {
    answer.insert(v);
    return;
  }

  for (int i = idx; i < n; i++) {
    v.push_back(arr[i]);
    dfs(i, cnt + 1);
    v.pop_back();
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  dfs(0, 0);

  for (auto vector : answer) {
    for (auto temp : vector) cout << temp << " ";
    cout << "\n";
  }

  return 0;
}