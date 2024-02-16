#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> plan;
int parent[201];

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
  freopen("example.txt", "r", stdin);
  cin >> N >> M;

  for (int i = 1; i <= N; i++) {
    parent[i] = i;
  }

  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      int connected;
      cin >> connected;
      if (connected == 1 && !sameParent(i, j)) unionParent(i, j);
    }
  }

  for (int i = 0; i < M; i++) {
    int a;
    cin >> a;
    plan.push_back(a);
  }

  for (int i = 0; i < M - 1; i++) {
    int from = plan[i];
    int to = plan[i + 1];
    if (!sameParent(from, to)) {
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";

  return 0;
}
