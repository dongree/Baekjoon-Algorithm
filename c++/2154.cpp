#include <iostream>
#include <string>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  string s = "";

  for (int i = 1; i <= N; i++) {
    s += to_string(i);
  }

  int result = s.find(to_string(N));

  cout << result + 1;

  return 0;
}