#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans;

vector<int> stack;

int main() {
  freopen("example.txt", "r", stdin);

  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(' && s[i + 1] == ')') {
      ans += stack.size();
      i++;
    } else if (s[i] == '(') {
      stack.push_back(s[i]);
    } else {
      stack.pop_back();
      ans++;
    }
  }

  cout << ans;

  return 0;
}