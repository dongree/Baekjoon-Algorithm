#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;
int n, m;

int arr[8];
bool isVisited[8];
set<vector<int>> answer;
vector<int> v;

void dfs(int cnt) {
  if (cnt == m) {
    answer.insert(v);
    return;
  }

  for (int i = 0; i < n; i++) {
    if (!isVisited[i]) {
      isVisited[i] = true;
      v.push_back(arr[i]);
      dfs(cnt + 1);
      v.pop_back();
      isVisited[i] = false;
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  sort(arr, arr + n);

  dfs(0);

  for (auto vector : answer) {
    for (auto temp : vector) cout << temp << " ";
    cout << "\n";
  }

  return 0;
}