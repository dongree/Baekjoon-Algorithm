#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> coins;

int main() {
  freopen("example.txt", "r", stdin);
  ll n, W;
  cin >> n >> W;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    coins.push_back(a);
  }

  for (int i = 0; i < n - 1; i++) {
    if (coins[i] < coins[i + 1]) {
      ll k = W / coins[i];
      W = W % coins[i];
      W += coins[i + 1] * k;
    }
  }

  cout << W;

  return 0;
}