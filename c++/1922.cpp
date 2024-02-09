#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int parent[1001];
vector<pair<int, pair<int, int>>> v;
int answer;

int getParent(int x) {
  if (x == parent[x])
    return x;
  else
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a > b)
    parent[a] = b;
  else
    parent[b] = a;
}

bool sameParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  return a == b;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    v.push_back({c, {a, b}});
  }

  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }

  sort(v.begin(), v.end());

  int cnt = 0;
  for (int i = 0; i < M; i++) {
    int weight = v[i].first;
    int from = v[i].second.first;
    int to = v[i].second.second;

    if (!sameParent(from, to)) {
      unionParent(from, to);
      answer += weight;
      cnt++;
    }

    if (cnt == N - 1) break;
  }

  cout << answer;

  return 0;
}