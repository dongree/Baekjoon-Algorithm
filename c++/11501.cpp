#include <iostream>

using namespace std;

int arr[1000000];

int main() {
  freopen("example.txt", "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    int maxV = 0;
    long long ans = 0;

    for (int i = N - 1; i >= 0; i--) {
      if (maxV < arr[i])
        maxV = arr[i];
      else if (maxV > arr[i])
        ans += maxV - arr[i];
    }

    cout << ans << '\n';
  }

  return 0;
}