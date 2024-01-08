#include <iostream>

using namespace std;

long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) { return a * b / gcd(a, b); }

int main() {
  // freopen("example.txt", "r", stdin);

  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    cout << lcm(a, b) << '\n';
  }

  return 0;
}
