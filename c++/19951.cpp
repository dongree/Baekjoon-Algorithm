#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int ps[100001];

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  while (M--) {
    int a, b, k;
    cin >> a >> b >> k;
    ps[a] += k;
    ps[b + 1] -= k;
  }

  for (int i = 1; i <= N; i++) {
    ps[i] += ps[i - 1];
  }

  for (int i = 0; i < N; i++) {
    cout << v[i] + ps[i + 1] << ' ';
  }

  return 0;
}