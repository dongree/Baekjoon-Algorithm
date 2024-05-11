#include <iostream>
#include <queue>
#include <string>

using namespace std;

queue<string> q;

int main() {
  freopen("example.txt", "r", stdin);

  string S, T;
  cin >> S >> T;

  q.push(T);

  while (!q.empty()) {
    string s = q.front();
    q.pop();

    cout << s << '\n';

    if (s.length() > T.length()) break;

    if (s == S) {
      cout << 1;
      return 0;
    }

    if (s.back() == 'A') {
      q.push(s.substr(0, s.length() - 1));
    }

    if (s[0] == 'B') {
      string cs = "";
      for (int i = 0; i < s.length(); i++) {
        cs = s[i] + cs;
      }

      q.push(cs.substr(0, cs.length() - 1));
    }
  }

  cout << 0;

  return 0;
}