#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> stack;

int main() {
  freopen("example.txt", "r", stdin);

  int N, K;
  cin >> N >> K;

  string s;
  cin >> s;

  for (int i = 0; i < s.length(); i++) {
    if (stack.size() == 0)
      stack.push_back(s[i]);
    else {
      while (K != 0 && stack.size() != 0 && stack.back() < s[i]) {
        stack.pop_back();
        K--;
      }
      stack.push_back(s[i]);
    }
  }

  while (K--) {
    stack.pop_back();
  }

  for (int i = 0; i < stack.size(); i++) {
    cout << stack[i];
  }

  return 0;
}