#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> stack;

int main() {
  freopen("example.txt", "r", stdin);

  string s, bombS;
  cin >> s >> bombS;
  int bombSize = bombS.length();

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == bombS[bombSize - 1]) {
      bool flag = false;

      if (stack.size() >= bombSize - 1) {
        for (int j = 0; j < bombSize - 1; j++) {
          if (stack[stack.size() - bombSize + 1 + j] != bombS[j]) {
            flag = true;
            break;
          }
        }
      } else {
        flag = true;
      }

      if (flag)
        stack.push_back(s[i]);
      else {
        for (int j = 0; j < bombSize - 1; j++) {
          stack.pop_back();
        }
      }
    } else {
      stack.push_back(s[i]);
    }
  }

  if (stack.size() == 0) {
    cout << "FRULA";
  } else {
    for (int i = 0; i < stack.size(); i++) {
      cout << stack[i];
    }
  }

  return 0;
}