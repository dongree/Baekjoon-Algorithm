#include <iostream>

typedef long long ll;

using namespace std;

int ccw(ll ax, ll ay, ll bx, ll by, ll cx, ll cy) {
  ll k = (bx - ax) * (cy - ay) - (cx - ax) * (by - ay);

  if (k > 0) return 1;
  if (k < 0) return -1;
  return 0;
}

int main() {
  freopen("example.txt", "r", stdin);
  ll x1, y1, x2, y2, x3, y3, x4, y4;

  cin >> x1 >> y1 >> x2 >> y2;
  cin >> x3 >> y3 >> x4 >> y4;

  if (ccw(x1, y1, x3, y3, x2, y2) * ccw(x1, y1, x4, y4, x2, y2) < 0 &&
      ccw(x3, y3, x1, y1, x4, y4) * ccw(x3, y3, x2, y2, x4, y4) < 0) {
    cout << 1;
  } else
    cout << 0;

  return 0;
}