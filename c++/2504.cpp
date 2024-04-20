#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> stack;

int sum = 0;
int num = 1;

int main() {
  freopen("example.txt", "r", stdin);

  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      stack.push_back(s[i]);
      num *= 2;
    } else if (s[i] == '[') {
      stack.push_back(s[i]);
      num *= 3;
    } else if (s[i] == ')') {
      if (stack.empty() || stack.back() != '(') {
        cout << 0;
        return 0;
      }
      if (s[i - 1] == '(') sum += num;
      stack.pop_back();
      num /= 2;
    } else if (s[i] == ']') {
      if (stack.empty() || stack.back() != '[') {
        cout << 0;
        return 0;
      }
      if (s[i - 1] == '[') sum += num;
      stack.pop_back();
      num /= 3;
    }
  }

  if (stack.empty())
    cout << sum;
  else
    cout << 0;

  return 0;
}