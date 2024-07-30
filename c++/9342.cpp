#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  regex re("^[A-F]?A+F+C+[A-F]?$");

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    if (regex_match(s, re))
      cout << "Infected!";
    else
      cout << "Good";

    cout << '\n';
  }

  return 0;
}