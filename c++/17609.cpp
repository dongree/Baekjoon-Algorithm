#include <iostream>
#include <string>

using namespace std;

bool check(string s, int start, int end) {
  while (start <= end) {
    if (s[start] != s[end]) return false;
    start++;
    end--;
  }
  return true;
}

int solve(string s) {
  int start = 0;
  int end = s.length() - 1;

  while (start <= end) {
    if (s[start] == s[end]) {
      start++;
      end--;
      continue;
    } else {
      if (check(s, start + 1, end) || check(s, start, end - 1)) {
        return 1;
      } else {
        return 2;
      }
    }
  }
  return 0;
}

int main() {
  freopen("example.txt", "r", stdin);
  int T;
  cin >> T;

  while (T--) {
    string s;
    cin >> s;

    cout << solve(s) << '\n';
  }

  return 0;
}