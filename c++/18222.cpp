#include <iostream>

typedef long long ll;

using namespace std;

int dc(ll idx) {
  if (idx == 0) return 0;

  if (idx % 2 == 0)
    return dc(idx / 2);
  else
    return 1 - dc(idx / 2);
}

int main() {
  freopen("example.txt", "r", stdin);
  ll k;
  cin >> k;

  cout << dc(k - 1);

  return 0;
}