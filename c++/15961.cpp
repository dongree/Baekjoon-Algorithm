#include <algorithm>
#include <iostream>

using namespace std;

int sushi[3000000];
int hasSushi[3000000];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  freopen("example.txt", "r", stdin);
  int N, d, k, c;

  cin >> N >> d >> k >> c;

  int cnt = 0;

  for (int i = 0; i < N; i++) {
    cin >> sushi[i];
    if (i < k) {
      if (hasSushi[sushi[i]] == 0) cnt++;
      hasSushi[sushi[i]]++;
    }
  }

  int answer = hasSushi[c] ? cnt : cnt + 1;

  for (int i = 0; i < N; i++) {
    if (hasSushi[sushi[i]] == 1) cnt--;
    hasSushi[sushi[i]]--;
    if (hasSushi[sushi[(i + k) % N]] == 0) cnt++;
    hasSushi[sushi[(i + k) % N]]++;
    answer = max(answer, hasSushi[c] ? cnt : cnt + 1);
  }

  cout << answer;

  return 0;
}