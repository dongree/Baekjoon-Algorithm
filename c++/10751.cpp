#include <iostream>
#include <string>
#include <vector>

typedef long long ll;

using namespace std;

ll L[100001];
ll R[100001];

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);

  int n;
  string s;

  cin >> n >> s;

  L[0] = (s[0] == 'C' ? 1 : 0);
  for (int i = 1; i < n; i++) {
    L[i] = L[i - 1] + (s[i] == 'C' ? 1 : 0);
  }

  R[n - 1] = (s[n - 1] == 'W' ? 1 : 0);
  for (int i = n - 2; i > 1; i--) {
    R[i] = R[i + 1] + (s[i] == 'W' ? 1 : 0);
  }

  ll ans = 0;
  for (int i = 1; i < n - 1; i++) {
    if (s[i] == 'O') {
      ans += L[i - 1] * R[i + 1];
    }
  }

  cout << ans;

  return 0;
}