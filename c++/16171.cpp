#include <iostream>
#include <string>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);
  string s, target;

  cin >> s >> target;

  string newS = "";

  for (int i = 0; i < s.length(); i++) {
    if ('0' <= s[i] && s[i] <= '9') {
      continue;
    }
    newS += s[i];
  }

  int ans = 0;

  for (int i = 0; i < newS.length(); i++) {
    if (newS[i] == target[0]) {
      bool flag = false;
      for (int j = i + 1; j < i + target.length(); j++) {
        if (newS[j] != target[j - i]) {
          flag = true;
          break;
        }
      }
      if (!flag) {
        ans = 1;
        break;
      }
    }
  }

  cout << ans;

  return 0;
}