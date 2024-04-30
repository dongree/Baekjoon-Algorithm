#include <iostream>
// #include <map>
#include <unordered_map>

using namespace std;

typedef long long ll;

ll N, P, Q;

unordered_map<ll, ll> dic;

ll recur(ll i) {
  if (i == 0) return 1;

  ll ip = i / P;
  ll iq = i / Q;

  if (dic[i])
    return dic[i];
  else
    return dic[i] = recur(ip) + recur(iq);
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> N >> P >> Q;

  cout << recur(N);

  return 0;
}