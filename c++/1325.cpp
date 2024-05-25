#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

vector<int> adjList[10001];
bool isVisited[10001];
int results[10001];
int cnt;
int maxCnt = 0;

void dfs(int n) {
  cnt++;

  for (int i = 0; i < adjList[n].size(); i++) {
    int nn = adjList[n][i];
    if (!isVisited[nn]) {
      isVisited[nn] = true;
      dfs(nn);
    }
  }
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    adjList[b].push_back(a);
  }

  for (int i = 1; i <= N; i++) {
    memset(isVisited, false, sizeof(isVisited));
    isVisited[i] = true;
    cnt = 0;

    dfs(i);

    if (cnt > maxCnt) maxCnt = cnt;
    results[i] = cnt;
  }

  for (int i = 1; i <= N; i++) {
    if (results[i] == maxCnt) {
      cout << i << ' ';
    }
  }

  return 0;
}