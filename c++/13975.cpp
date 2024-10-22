#include <iostream>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  int T;
  cin >> T;

  while (T--) {
    ll result = 0;
    int N;
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    cin >> N;

    while (N--) {
      int a;
      cin >> a;
      pq.push(a);
    }

    while (pq.size() != 1) {
      ll a = pq.top();
      pq.pop();
      ll b = pq.top();
      pq.pop();
      ll c = a + b;
      result += c;
      pq.push(c);
    }

    cout << result << '\n';
  }

  return 0;
}