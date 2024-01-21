#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> node[10001];
bool isVisited[10001];

int n;
int result = 0;
int endPoint = 0;

void init() {
  result = 0;
  for (int i = 1; i <= n; i++) {
    isVisited[i] = false;
  }
}

void dfs(int num, int weight) {
  if (result < weight) {
    result = weight;
    endPoint = num;
  }
  for (int i = 0; i < node[num].size(); i++) {
    int nextNum = node[num][i].first;
    int nextWeight = node[num][i].second;
    if (!isVisited[nextNum]) {
      isVisited[nextNum] = true;
      dfs(nextNum, weight + nextWeight);
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    node[a].push_back({b, c});
    node[b].push_back({a, c});
  }

  isVisited[1] = true;
  dfs(1, 0);

  init();

  isVisited[endPoint] = true;
  dfs(endPoint, 0);

  cout << result;

  return 0;
}