#include <iostream>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  long long N;
  long long s = 1;
  long long result = 0;

  cin >> N;

  while (N != 0) {
    if (N & 1) result += s;
    s *= 3;
    N >>= 1;
  }

  cout << result;

  return 0;
}