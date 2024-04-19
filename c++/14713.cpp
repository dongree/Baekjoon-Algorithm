#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> stack;
vector<char> ans;

int main() {
  freopen("example.txt", "r", stdin);

  string s;

  getline(cin, s);
  bool isWord = true;

  for (int i = 0; i < s.length(); i++) {
    if (isWord) {
      if (s[i] == '<') {
        isWord = false;
        while (!stack.empty()) {
          int a = stack.back();
          ans.push_back(a);
          stack.pop_back();
        }
        ans.push_back(s[i]);
      } else if (s[i] == ' ') {
        while (!stack.empty()) {
          int a = stack.back();
          ans.push_back(a);
          stack.pop_back();
        }
        ans.push_back(s[i]);
      } else {
        stack.push_back(s[i]);
      }
    } else {
      if (s[i] == '>') {
        isWord = true;
        ans.push_back(s[i]);
      } else {
        ans.push_back(s[i]);
      }
    }
  }
  while (!stack.empty()) {
    int a = stack.back();
    ans.push_back(a);
    stack.pop_back();
  }

  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i];
  }

  return 0;
}