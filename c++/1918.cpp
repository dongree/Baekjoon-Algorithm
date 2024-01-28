#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> stack;
string answer = "";

int main() {
  freopen("example.txt", "r", stdin);
  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      answer += s[i];
    } else if (s[i] == '(') {
      stack.push_back(s[i]);
    } else if (s[i] == ')') {
      while (stack.size() && stack.back() != '(') {
        answer += stack.back();
        stack.pop_back();
      }
      stack.pop_back();
    } else if (s[i] == '+' || s[i] == '-') {
      while (stack.size() && stack.back() != '(') {
        answer += stack.back();
        stack.pop_back();
      }
      stack.push_back(s[i]);
    } else if (s[i] == '*' || s[i] == '/') {
      while (stack.size() && (stack.back() == '*' || stack.back() == '/')) {
        answer += stack.back();
        stack.pop_back();
      }
      stack.push_back(s[i]);
    }
  }

  while (stack.size()) {
    answer += stack.back();
    stack.pop_back();
  }

  cout << answer;

  return 0;
}