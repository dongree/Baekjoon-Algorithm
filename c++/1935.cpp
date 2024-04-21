#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<char, int> dic;
vector<double> stack;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  string s;
  cin >> s;

  for (int i = 0; i < N; i++) {
    int value;
    cin >> value;
    dic[char('A' + i)] = value;
  }

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '*' || s[i] == '+' || s[i] == '/' || s[i] == '-') {
      double b = stack.back();
      stack.pop_back();
      double a = stack.back();
      stack.pop_back();
      double result;

      if (s[i] == '*') {
        result = a * b;
      } else if (s[i] == '+') {
        result = a + b;
      } else if (s[i] == '/') {
        result = a / b;
      } else if (s[i] == '-') {
        result = a - b;
      }
      stack.push_back(result);
    } else {
      stack.push_back(dic[s[i]]);
    }
  }

  cout << fixed;
  cout.precision(2);

  cout << stack[0];

  return 0;
}