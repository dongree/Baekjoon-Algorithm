#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, pair<int, int>>> v;
int parent[10001];
int answer;

int getParent(int x) {
  if (parent[x] == x) return x;
  return parent[x] = getParent(parent[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  parent[b] = a;
}

bool sameParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);
  if (a == b)
    return true;
  else
    return false;
}

int main() {
  freopen("example.txt", "r", stdin);
  int V, E;
  cin >> V >> E;

  for (int i = 0; i < E; i++) {
    int A, B, C;
    cin >> A >> B >> C;
    v.push_back({C, {A, B}});
  }

  sort(v.begin(), v.end());

  for (int i = 1; i <= V; i++) {
    parent[i] = i;
  }

  int cnt = 0;
  for (int i = 0; i < E; i++) {
    int weight = v[i].first;
    int from = v[i].second.first;
    int to = v[i].second.second;

    if (!sameParent(from, to)) {
      unionParent(from, to);
      answer += weight;
      cnt++;
    }

    if (cnt == V - 1) break;
  }

  cout << answer;

  return 0;
}