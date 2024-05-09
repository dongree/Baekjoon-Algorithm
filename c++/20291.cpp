#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> dic;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  string s;

  while (N--) {
    cin >> s;
    string ext = s.substr(s.find('.') + 1);
    if (dic[ext] == 0) {
      dic[ext] = 1;
    } else {
      dic[ext]++;
    }
  }

  for (auto iter = dic.begin(); iter != dic.end(); iter++) {
    cout << iter->first << ' ' << iter->second << '\n';
  }

  return 0;
}