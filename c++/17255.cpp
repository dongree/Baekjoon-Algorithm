#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

int N;
string s;
unordered_set<string> ust;

void dfs(int left, int right, string str, string id) {
  if (left == 0 && right == N - 1) {
    ust.insert(id);
    return;
  }

  if (left >= 1) {
    dfs(left - 1, right, s[left - 1] + str, id + s[left - 1] + str);
  }

  if (right < N - 1) {
    dfs(left, right + 1, str + s[right + 1], id + str + s[right + 1]);
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> s;
  N = s.length();

  for (int i = 0; i < N; i++) {
    dfs(i, i, string(1, s[i]), string(1, s[i]));
  }

  cout << ust.size();

  return 0;
}