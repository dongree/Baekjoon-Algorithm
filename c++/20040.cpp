#include <iostream>

using namespace std;

int arr[1000000][2];
int parent[500000];

int getParent(int x) {
  if (parent[x] == x)
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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int a = arr[i][0];
    int b = arr[i][1];

    if (!sameParent(a, b)) {
      unionParent(a, b);
    } else {
      cout << i + 1;
      return 0;
    }
  }

  cout << 0;

  return 0;
}