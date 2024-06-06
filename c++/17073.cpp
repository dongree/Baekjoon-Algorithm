#include <iostream>
#include <vector>

using namespace std;

vector<int> adjList[500001];
bool isVisited[500001];

double cnt;

void dfs(int n) {
  int cnCnt = 0;
  for (int i = 0; i < adjList[n].size(); i++) {
    int nn = adjList[n][i];

    if (!isVisited[nn]) {
      cnCnt++;
      isVisited[nn] = true;
      dfs(nn);
      isVisited[nn] = false;
    }
  }

  if (cnCnt == 0) cnt++;
}

int main() {
  freopen("example.txt", "r", stdin);

  int N, W;
  cin >> N >> W;

  int a, b;
  while (cin >> a >> b) {
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  isVisited[1] = true;
  dfs(1);

  cout.precision(10);

  cout << W / cnt;

  return 0;
}