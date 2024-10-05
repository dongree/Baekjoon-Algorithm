#include <iostream>
#include <string>

using namespace std;

int N;
bool flag = false;

bool check(string s) {
  int n = s.length();
  if (n == 1) return true;

  for (int i = 1; i <= n / 2; i++) {
    string a = s.substr(n - i, i);
    string b = s.substr(n - i * 2, i);

    if (a == b) return false;
  }

  return true;
}

void dfs(int cnt, string s) {
  if (flag) return;

  if (cnt == N) {
    cout << s << '\n';
    flag = true;
    return;
  }

  for (int i = 1; i <= 3; i++) {
    string next = s + to_string(i);
    if (check(next)) {
      dfs(cnt + 1, next);
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N;

  dfs(0, "");

  return 0;
}