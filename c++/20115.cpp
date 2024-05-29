#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<double> drinks;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    double a;
    cin >> a;
    drinks.push_back(a);
  }

  sort(drinks.begin(), drinks.end(), greater<double>());

  double ans = 0;

  ans += drinks[0];

  double k = 0;
  for (int i = 1; i < N; i++) {
    k += drinks[i];
  }
  ans += k / 2;

  cout << ans;

  return 0;
}