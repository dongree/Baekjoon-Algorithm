#include <cmath>
#include <iostream>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  int t;
  cin >> t;
  for (int tc = 0; tc < t; tc++) {
    long long x, y;
    cin >> x >> y;
    long long distance = y - x;
    long long answer;

    long long i = 1;
    while (i * i <= distance) {
      i++;
    }
    i -= 1;

    if (i * i == distance) {
      answer = i * 2 - 1;
    } else {
      long long bottom = i * i;
      long long top = (i + 1) * (i + 1);
      long long middle = bottom + (top - bottom - 1) / 2;

      if (distance <= middle)
        answer = 2 * i;
      else
        answer = 2 * i + 1;
    }
    cout << answer << '\n';
  }

  return 0;
}