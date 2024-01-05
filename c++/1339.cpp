#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
int a[26];

bool cmp(int a, int b) { return a > b; }

int main() {
  freopen("example.txt", "r", stdin);

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    int v = 1;
    for (int j = s.size() - 1; j >= 0; j--) {
      a[s[j] - 'A'] += v;
      v *= 10;
    }
  }
  sort(a, a + 26, cmp);

  int answer = 0;
  for (int i = 0; i < 9; i++) {
    answer += a[i] * (9 - i);
  }
  cout << answer;

  return 0;
}