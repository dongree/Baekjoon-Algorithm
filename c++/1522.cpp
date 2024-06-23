#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);
  string s;
  cin >> s;

  int len = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'a') len++;
  }

  s += s.substr(0, len - 1);

  int ans = len;

  for (int i = 0; i <= s.length() - len; i++) {
    string ss = s.substr(i, len);
    int cnt = 0;
    for (int j = 0; j < ss.length(); j++) {
      if (ss[j] == 'b') cnt++;
    }
    ans = min(ans, cnt);
  }

  cout << ans;

  return 0;
}