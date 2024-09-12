#include <iostream>

using namespace std;

typedef long long ll;

bool isPrime(ll n) {
  if (n < 2) return false;

  for (ll i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }

  return true;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  freopen("example.txt", "r", stdin);

  int T;
  cin >> T;

  while (T--) {
    ll n;
    cin >> n;
    while (!isPrime(n)) n++;
    cout << n << '\n';
  }

  return 0;
}