// my solution
// #include <iostream>
// #include <vector>

// using namespace std;

// vector<pair<long long, int>> stack;
// long long ans;

// int main() {
//   freopen("example.txt", "r", stdin);

//   int N;
//   cin >> N;

//   for (int i = 0; i < N; i++) {
//     long long a;
//     cin >> a;

//     while (stack.size() > 0 && stack.back().first <= a) {
//       ans += i - stack.back().second - 1;
//       stack.pop_back();
//     }
//     stack.push_back({a, i});
//   }

//   while (stack.size() != 0) {
//     ans += N - stack.back().second - 1;
//     stack.pop_back();
//   }

//   cout << ans;
//   return 0;
// }

// another solution
#include <iostream>
#include <vector>

using namespace std;

vector<long long> stack;
long long ans;

int main() {
  freopen("example.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    long long a;
    cin >> a;

    while (!stack.empty() && stack.back() <= a) {
      stack.pop_back();
    }
    ans += stack.size();
    stack.push_back(a);
  }

  cout << ans;
  return 0;
}