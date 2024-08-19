#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int arr[1001][1001];
vector<pair<int, pair<int, int>>> edges;
int parents[1001];

int getParent(int x) {
  if (x == parents[x])
    return x;
  else
    return parents[x] = getParent(parents[x]);
}

void unionParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a > b)
    parents[a] = b;
  else if (a < b)
    parents[b] = a;
}

bool sameParent(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  return a == b;
}

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 1; i <= N; i++) {
    for (int j = i + 1; j <= N; j++) {
      edges.push_back({arr[i][j], {i, j}});
    }
  }
  sort(edges.begin(), edges.end());

  for (int i = 1; i <= N; i++) {
    parents[i] = i;
  }

  int cnt = 0;
  long long result = 0;

  for (int i = 0; i < edges.size(); i++) {
    int cost = edges[i].first;
    int a = edges[i].second.first;
    int b = edges[i].second.second;

    if (!sameParent(a, b)) {
      unionParent(a, b);
      result += cost;
      cnt++;
    }

    if (cnt == N - 1) break;
  }

  cout << result;
  return 0;
}