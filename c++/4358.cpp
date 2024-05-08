#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

vector<string> vs;
map<string, double> dic;

int main() {
  string s;
  freopen("example.txt", "r", stdin);

  while (getline(cin, s)) {
    vs.push_back(s);
  }

  sort(vs.begin(), vs.end());

  for (int i = 0; i < vs.size(); i++) {
    if (dic[vs[i]] == 0) {
      dic[vs[i]] = 1;
    } else {
      dic[vs[i]]++;
    }
  }

  int n = vs.size();

  cout << fixed;
  cout.precision(4);

  for (auto iter = dic.begin(); iter != dic.end(); iter++) {
    cout << iter->first << ' ' << (iter->second * 100) / n << '\n';
  }

  return 0;
}