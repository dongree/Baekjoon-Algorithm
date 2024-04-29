#include <iostream>
#include <set>

using namespace std;

int train[100001];

set<int> s;

int main() {
  freopen("example.txt", "r", stdin);
  int N, M, i, x;
  cin >> N >> M;

  while (M--) {
    int c;
    cin >> c;

    if (c == 1) {
      cin >> i >> x;
      train[i] |= (1 << x);
    } else if (c == 2) {
      cin >> i >> x;
      train[i] &= ~(1 << x);
    } else if (c == 3) {
      cin >> i;
      train[i] <<= 1;
      train[i] &= ~(1 << 21);
    } else if (c == 4) {
      cin >> i;
      train[i] >>= 1;
      train[i] &= ~1;
    }
  }

  for (int i = 1; i <= N; i++) {
    s.insert(train[i]);
  }

  cout << s.size();

  return 0;
}