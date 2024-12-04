#include <iostream>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  int k = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (a == 0) k++;
  }

  if (k > N - k)
    cout << "Junhee is not cute!";
  else
    cout << "Junhee is cute!";

  return 0;
}