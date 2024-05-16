#include <iostream>

using namespace std;

int parents[100001];
int ans;

int getParent(int x) {
  if (x == parents[x])
    return x;
  else
    return parents[x] = getParent(parents[x]);
}

void unionParend(int a, int b) {
  a = getParent(a);
  b = getParent(b);

  if (a > b)
    parents[a] = b;
  else if (a < b)
    parents[b] = a;
}

int main() {
  freopen("example.txt", "r", stdin);
  int G, P;

  cin >> G >> P;

  for (int i = 1; i <= G; i++) {
    parents[i] = i;
  }

  while (P--) {
    int g;
    cin >> g;

    int gp = getParent(g);

    if (gp != 0) {
      unionParend(gp, gp - 1);
      ans++;
    } else
      break;
  }

  cout << ans;

  return 0;
}