#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
  freopen("example.txt", "r", stdin);

  string s;
  cin >> s;

  regex re("^(100+1+|01)+$");

  if (regex_match(s, re))
    cout << "SUBMARINE";
  else
    cout << "NOISE";

  return 0;
}