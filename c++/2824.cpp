#include <iostream>

typedef long long ll;

using namespace std;

int N, M;
int A[1000];
int B[1000];

ll gcd(ll a, ll b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }

  ll ans = 1;
  bool isBig = false;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      ll gc = gcd(A[i], B[j]);
      ans *= gc;

      A[i] /= gc;
      B[j] /= gc;

      if (ans >= 1000000000) {
        isBig = true;
        ans %= 1000000000;
      }
    }
  }
  if (isBig)
    printf("%09lld", ans);
  else
    cout << ans;

  return 0;
}