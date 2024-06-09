#include <iostream>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
  int k = (x2 - x1) * (y3 - y1) - (x3 - x1) * (y2 - y1);

  if (k > 0)
    return 1;
  else if (k < 0)
    return -1;
  return 0;
}

int main() {
  freopen("example.txt", "r", stdin);

  int x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

  cout << ccw(x1, y1, x2, y2, x3, y3);

  return 0;
}