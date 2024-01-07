#include <iostream>
#include <vector>

using namespace std;

int n, m;
bool badCombi[201][201];
int answer = 0;
vector<int> v;

void dfs(int idx, int cnt) {
  if (cnt == 3) {
    answer++;
    return;
  }

  for (int i = idx; i <= n; i++) {
    bool flag = false;
    for (int j = 0; j < v.size(); j++) {
      if (badCombi[i][v[j]]) {
        flag = true;
        break;
      }
    }
    if (flag) continue;
    v.push_back(i);
    dfs(i + 1, cnt + 1);
    v.pop_back();
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    badCombi[a][b] = true;
    badCombi[b][a] = true;
  }

  dfs(1, 0);
  cout << answer;

  return 0;
}