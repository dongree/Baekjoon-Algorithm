#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);
  int t;
  cin >> t;

  for (int tc = 0; tc < t; tc++) {
    string p, s;
    int n;
    cin >> p >> n >> s;

    vector<string> v;
    string ss = "";
    for (int i = 1; i < s.length(); i++) {
      if ((s[i] == ']' || s[i] == ',') && ss.length() != 0) {
        v.push_back(ss);
        ss = "";
      } else {
        ss += s[i];
      }
    }

    bool isFlip = false;
    int start = 0;
    int end = n;

    for (int i = 0; i < p.length(); i++) {
      if (p[i] == 'R')
        isFlip = !isFlip;
      else
        isFlip ? end-- : start++;
    }

    if (start > end)
      cout << "error" << '\n';
    else {
      cout << '[';
      for (int i = 0; i < end - start; i++) {
        cout << (isFlip ? v[end - 1 - i] : v[start + i]);
        if (i != end - start - 1) cout << ',';
      }
      cout << "]\n";
    }
  }

  return 0;
}