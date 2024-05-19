#include <iostream>
#include <string>

using namespace std;

string c[101][101];

string add(string a, string b) {
  string result = "";

  if (a.length() > b.length()) {
    while (b.length() != a.length()) {
      b = "0" + b;
    }
  } else {
    while (b.length() != a.length()) {
      a = "0" + a;
    }
  }

  bool flag = false;
  for (int i = a.length() - 1; i >= 0; i--) {
    int val = (a[i] - '0') + (b[i] - '0');

    if (flag) val += 1;

    if (val >= 10)
      flag = true;
    else
      flag = false;

    result = to_string(val % 10) + result;
  }

  if (flag) result = '1' + result;

  return result;
}

string comb(int n, int m) {
  if (n == m || m == 0) return c[n][m] = "1";
  if (c[n][m] != "") return c[n][m];
  return c[n][m] = add(comb(n - 1, m), comb(n - 1, m - 1));
}

int main() {
  freopen("example.txt", "r", stdin);

  int n, m;
  cin >> n >> m;

  cout << comb(n, m);
  return 0;
}