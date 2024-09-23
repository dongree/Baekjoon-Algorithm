#include <iostream>

using namespace std;

int arr[13];
int sum = 0;
int cnt = 0;
int k;
bool visited[3000000];

void recur(int n, int curr) {
  if (curr >= 1 && !visited[curr]) {
    cnt++;
    visited[curr] = true;
  }

  if (n == k) return;

  recur(n + 1, curr);
  recur(n + 1, curr - arr[n]);
  recur(n + 1, curr + arr[n]);
}

int main() {
  freopen("example.txt", "r", stdin);
  cin >> k;

  for (int i = 0; i < k; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  recur(0, 0);

  cout << sum - cnt;

  return 0;
}