#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  regex re("^((100+1+)|01)+$");

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    if (regex_match(s, re))
      cout << "YES";
    else
      cout << "NO";

    cout << '\n';
  }

  return 0;
}