#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}

int main() {
  freopen("example.txt", "r", stdin);
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int M, N, x, y;
    cin >> M >> N >> x >> y;

    int lcm = M * N / gcd(M, N);
    while (true) {
      if (x > lcm && y > lcm) {
        cout << -1 << '\n';
        break;
      } else if (x > y)
        y += N;
      else if (x < y)
        x += M;
      else {
        cout << x << '\n';
        break;
      }
    }
  }

  return 0;
}