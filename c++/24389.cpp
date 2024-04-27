#include <iostream>

typedef long long ll;

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  ll N;
  cin >> N;
  ll M = ~N + 1;

  int cnt = 0;

  for (int i = 0; i < 32; i++) {
    if ((N & 1) != (M & 1)) cnt++;
    N >>= 1;
    M >>= 1;
  }

  cout << cnt;

  return 0;
}
