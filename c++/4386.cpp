#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

double coords[100][2];
vector<pair<double, pair<double, double>>> edges;
int parent[10001];

int getParent(int x) {
  if (x == parent[x])
    return x;
  else
    return parent[x] = getParent(parent[x]);
}

void unionParnet(int a, int b) {
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

  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> coords[i][0] >> coords[i][1];
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = i + 1; j < n; j++) {
      double x1 = coords[i][0];
      double y1 = coords[i][1];
      double x2 = coords[j][0];
      double y2 = coords[j][1];

      double weight = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));
      edges.push_back({weight, {i, j}});
    }
  }
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  sort(edges.begin(), edges.end());

  double answer = 0;
  for (int i = 0; i < edges.size(); i++) {
    double weight = edges[i].first;
    int a = edges[i].second.first;
    int b = edges[i].second.second;

    if (!sameParent(a, b)) {
      unionParnet(a, b);
      answer += weight;
    }
  }

  cout << answer;

  return 0;
}