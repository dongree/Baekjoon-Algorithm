#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> v;

int checked;
int word[50];

int N, K, ans;

void dfs(int cnt, int idx) {
  if (cnt == K) {
    int c = 0;
    for (int i = 0; i < N; i++) {
      if ((word[i] & checked) == word[i]) c++;
    }
    if (ans < c) ans = c;
    return;
  }

  for (int i = idx; i < 26; i++) {
    if ((checked & (1 << i)) == 0) {
      checked |= 1 << i;
      dfs(cnt + 1, i + 1);
      checked &= ~(1 << i);
    }
  }
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> K;

  string s;
  for (int i = 0; i < N; i++) {
    cin >> s;

    int num = 0;
    for (int j = 0; j < s.length(); j++) {
      num |= 1 << (s[j] - 'a');
    }
    word[i] = num;
  }

  if (K < 5) {
    cout << 0;
    return 0;
  }

  checked |= 1 << ('a' - 'a');
  checked |= 1 << ('n' - 'a');
  checked |= 1 << ('t' - 'a');
  checked |= 1 << ('i' - 'a');
  checked |= 1 << ('c' - 'a');

  K -= 5;

  dfs(0, 0);

  cout << ans;

  return 0;
}