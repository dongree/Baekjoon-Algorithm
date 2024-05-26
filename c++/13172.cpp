#include <iostream>

#define MOD 1000000007

typedef long long ll;

using namespace std;

ll mul(int a, int n) {
  if (n == 1) return a % MOD;
  if (n % 2 == 0) {
    ll temp = mul(a, n / 2);
    return (temp * temp) % MOD;
  } else {
    return (a * mul(a, n - 1)) % MOD;
  }
}

ll getAns(int N, int S) { return (S * mul(N, MOD - 2)) % MOD; }

int main() {
  freopen("example.txt", "r", stdin);

  int M;
  cin >> M;
  ll ans = 0;

  while (M--) {
    int N, S;
    cin >> N >> S;
    ans = (ans + getAns(N, S)) % MOD;
  }

  cout << ans;

  return 0;
}