#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  vector<int> v;
  int minV = 1e9;

  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int snowman1 = v[i] + v[j];

      int start = 0;
      int end = N - 1;

      while (start < end) {
        if (start == i || start == j) {
          start++;
          continue;
        }
        if (end == i || end == j) {
          end--;
          continue;
        }

        int snowman2 = v[start] + v[end];
        minV = min(minV, abs(snowman1 - snowman2));

        if (snowman1 > snowman2)
          start++;
        else if (snowman1 < snowman2)
          end--;
        else {
          cout << 0;
          return 0;
        }
      }
    }
  }

  cout << minV;

  return 0;
}