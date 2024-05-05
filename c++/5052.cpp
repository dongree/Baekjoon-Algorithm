#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    vector<string> v;

    while (N--) {
      string s;
      cin >> s;
      v.push_back(s);
    }

    sort(v.begin(), v.end());

    string preS = v[0];
    int preL = preS.length();
    string ans = "YES";

    for (int i = 1; i < v.size(); i++) {
      if (v[i].substr(0, preL) == preS) {
        ans = "NO";
        break;
      }
      preS = v[i];
      preL = v[i].length();
    }
    cout << ans << '\n';
  }

  return 0;
}