#include <iostream>
#include <vector>

using namespace std;

vector<int> tree[51];
bool isVisited[51];
int cnt = 0;
int N, K;
int root = 0;

int dfs(int n) {
  if (n == K) {
    return -1;
  }

  if (tree[n].size() == 0) {
    cnt++;
    return 0;
  }

  for (int i = 0; i < tree[n].size(); i++) {
    int node = tree[n][i];
    if (isVisited[node]) continue;

    isVisited[node] = true;
    int temp = dfs(node);
    if (temp == -1 && tree[n].size() == 1) cnt++;
    isVisited[node] = false;
  }

  return 0;
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a == -1) {
      root = i;
      continue;
    }
    tree[a].push_back(i);
  }

  cin >> K;

  isVisited[root] = true;
  dfs(root);

  cout << cnt;

  return 0;
}