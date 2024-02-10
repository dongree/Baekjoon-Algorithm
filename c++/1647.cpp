#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> v;
int parent[100001];
int answer;
int cnt;

int getParent(int x) {
  if (x == parent[x])
    return x;
  else
    return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a < b)
    parent[b] = a;
  else
    parent[a] = b;
}

bool sameParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  return a == b;
}

int main() {
  freopen("example.txt", "r", stdin);

  int N, M;
  cin >> N >> M;

  if (N == 2) {
    cout << 0;
    return 0;
  }

  for (int i = 0; i < M; i++) {
    int a, b, c;
    cin >> a >> b >> c;

    v.push_back({c, {a, b}});
  }

  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < M; i++) {
    int weight = v[i].first;
    int from = v[i].second.first;
    int to = v[i].second.second;

    if (!sameParent(from, to)) {
      unionParent(from, to);
      cnt++;
      answer += weight;
    }

    if (cnt == N - 2) break;
  }

  cout << answer;

  return 0;
}