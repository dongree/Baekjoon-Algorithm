#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int l, c;
vector<char> alphabets;
vector<char> code;

void dfs(int idx, int cnt) {
  if (cnt == l) {
    int vowelLength = 0;
    for (int i = 0; i < l; i++) {
      if (code[i] == 'a' || code[i] == 'e' || code[i] == 'i' ||
          code[i] == 'o' || code[i] == 'u') {
        vowelLength++;
      }
    }
    if (0 < vowelLength && vowelLength <= l - 2) {
      std::string str(code.begin(), code.end());
      cout << str << '\n';
    }
  }

  for (int i = idx; i < c; i++) {
    code.push_back(alphabets[i]);
    dfs(i + 1, cnt + 1);
    code.pop_back();
  }
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> l >> c;

  for (int i = 0; i < c; i++) {
    char c;
    cin >> c;
    alphabets.push_back(c);
  }
  sort(alphabets.begin(), alphabets.end());

  dfs(0, 0);
  return 0;
}