#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> positive;
vector<int> negative;
int ans;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  while (N--) {
    int a;
    cin >> a;

    if (a > 0)
      positive.push_back(a);
    else
      negative.push_back(a);
  }

  sort(positive.begin(), positive.end(), greater<>());
  sort(negative.begin(), negative.end());

  int pSize = positive.size();
  int nSize = negative.size();

  for (int i = 0; i < pSize; i++) {
    if (i == pSize - 1) {
      ans += positive[i];
    } else {
      int a = positive[i];
      int b = positive[i + 1];

      if (a * b > a + b) {
        ans += a * b;
        i++;
      } else {
        ans += a;
      }
    }
  }

  for (int i = 0; i < nSize; i++) {
    if (i == nSize - 1) {
      ans += negative[i];
    } else {
      int a = negative[i];
      int b = negative[i + 1];

      if (a * b > a + b) {
        ans += a * b;
        i++;
      } else {
        ans += a;
      }
    }
  }

  cout << ans;

  return 0;
}