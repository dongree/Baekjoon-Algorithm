// my solution : pq

// #include <iostream>
// #include <queue>

// using namespace std;

// struct compare {
//   bool operator()(string a, string b) {
//     if (a.length() == b.length()) {
//       return a > b;
//     }
//     return a.length() > b.length();
//   }
// };

// priority_queue<string, vector<string>, compare> pq;

// int main() {
//   freopen("example.txt", "r", stdin);

//   long long a, b;
//   cin >> a >> b;

//   pq.push("4");
//   pq.push("7");

//   int aa = -1;
//   int bb = -1;

//   int cnt = 0;
//   while (!pq.empty()) {
//     string s = pq.top();
//     pq.pop();

//     if (aa == -1 && stol(s) >= a) {
//       aa = cnt;
//     }

//     if (bb == -1 && stol(s) > b) {
//       bb = cnt;
//       break;
//     }

//     pq.push(s + '4');
//     pq.push(s + '7');

//     cnt++;
//   }

//   cout << bb - aa;

//   return 0;
// }

// other solution
#include <iostream>

using namespace std;

int a, b;
int result = 0;

void recursion(long long num) {
  if (num > b) return;

  if (a <= num && num <= b) result++;

  recursion(num * 10 + 4);
  recursion(num * 10 + 7);
}

int main() {
  freopen("example.txt", "r", stdin);

  cin >> a >> b;

  recursion(0);

  cout << result;

  return 0;
}