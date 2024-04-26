#include <iostream>
#include <queue>

using namespace std;

priority_queue<long long, vector<long long>, greater<long long>> pq;
long long ans;

int main() {
  freopen("example.txt", "r", stdin);

  int n, m;
  cin >> n >> m;

  while (n--) {
    int a;
    cin >> a;
    pq.push(a);
  }

  while (m--) {
    long long a = pq.top();
    pq.pop();
    long long b = pq.top();
    pq.pop();

    long long k = a + b;
    pq.push(k);
    pq.push(k);
  }

  while (!pq.empty()) {
    ans += pq.top();
    pq.pop();
  }

  cout << ans;

  return 0;
}