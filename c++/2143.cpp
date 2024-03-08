#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);
  ll T;
  cin >> T;

  vector<ll> A;
  ll n;
  cin >> n;

  for (ll i = 0; i < n; i++) {
    ll e;
    cin >> e;
    A.push_back(e);
  }

  vector<ll> B;
  ll m;
  cin >> m;

  for (ll i = 0; i < m; i++) {
    ll e;
    cin >> e;
    B.push_back(e);
  }

  map<ll, ll> mapp;

  for (ll i = 0; i < n; i++) {
    ll sum = 0;
    for (ll j = i; j < n; j++) {
      sum += A[j];
      if (mapp.find(sum) == mapp.end()) {
        mapp.insert({sum, 1});
      } else {
        mapp[sum] += 1;
      }
    }
  }

  ll answer = 0;

  for (ll i = 0; i < m; i++) {
    ll sum = 0;
    for (ll j = i; j < m; j++) {
      sum += B[j];
      if (mapp.find(T - sum) != mapp.end()) {
        answer += mapp[(T - sum)];
      }
    }
  }

  cout << answer;

  return 0;
}