#include <iostream>

using namespace std;

long long A, B, C;

long long solve(long long power) {
  if (power == 0) return 1;
  if (power == 1) return A % C;

  long long half = solve(power / 2) % C;

  if (power % 2 == 1)
    return half * half % C * A % C;
  else
    return (half * half) % C;
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> A >> B >> C;

  cout << solve(B);
  return 0;
}