#include <iostream>
#include <map>
#include <string>

typedef long long ll;

using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

map<pair<string, string>, ll> dic;
map<string, ll> ans;

int main() {
  freopen("example.txt", "r", stdin);

  int N, F;
  string L;
  cin >> N >> L >> F;

  for (int i = 1; i <= 12; i++) {
    days[i] += days[i - 1];
  }

  ll criM = stoi(L.substr(0, 3)) * 24 * 60 + stoi(L.substr(4, 2)) * 60 +
            stoi(L.substr(7, 2));

  while (N--) {
    string d, t, P, M;
    cin >> d >> t >> P >> M;
    ll value =
        (days[stoi(d.substr(5, 2)) - 1] + stoi(d.substr(8, 2))) * 24 * 60 +
        stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));

    if (dic.find({P, M}) == dic.end()) {
      dic.insert({{P, M}, value});
    } else {
      ll preValue = dic[{P, M}];
      ll gap = value - preValue;
      if (gap > criM) {
        ll cost = (gap - criM) * F;
        ans[M] += cost;
      }
      dic.erase({P, M});
    }
  }

  if (ans.size() == 0)
    cout << -1;
  else {
    for (auto iter = ans.begin(); iter != ans.end(); iter++) {
      cout << iter->first << ' ' << iter->second << '\n';
    }
  }

  return 0;
}