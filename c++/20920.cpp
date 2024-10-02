#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

string s;
vector<string> v;
unordered_map<string, int> dic;

bool compare(string a, string b) {
  if (dic[a] == dic[b]) {
    if (a.length() == b.length()) {
      return a < b;
    }
    return a.length() > b.length();
  }
  return dic[a] > dic[b];
}

int main() {
  freopen("example.txt", "r", stdin);
  int N, M;
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> s;
    if (dic.find(s) == dic.end()) {
      if (s.length() >= M) v.push_back(s);
      dic[s] = 1;
    } else
      dic[s]++;
  }

  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < v.size(); i++) {
    cout << v[i] << '\n';
  }

  return 0;
}