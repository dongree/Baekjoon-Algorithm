// #include <algorithm>
// #include <iostream>

// using namespace std;

// vector<pair<int, int>> v;

// bool compare(pair<int, int> A, pair<int, int> B) {
//   if (A.second == B.second) return A.first < B.first;
//   return A.second < B.second;
// };

// int main() {
//   freopen("example.txt", "r", stdin);
//   int N;
//   cin >> N;

//   for (int i = 0; i < N; i++) {
//     int a, b;
//     cin >> a >> b;
//     v.push_back({a, b});
//   }

//   sort(v.begin(), v.end(), compare);

//   int k = 0;
//   int answer = 0;

//   for (int i = 0; i < N; i++) {
//     if (v[i].first >= k) {
//       k = v[i].second;
//       answer++;
//     }
//   }

//   cout << answer;
//   return 0;
// }

#include <algorithm>
#include <iostream>

using namespace std;

vector<pair<int, int>> v;

bool compare(pair<int, int> A, pair<int, int> B) {
  if (A.second == B.second) return A.first < B.first;
  return A.second < B.second;
};

int main() {
  freopen("example.txt", "r", stdin);
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    v.push_back({b, a});
  }

  sort(v.begin(), v.end());

  int k = 0;
  int answer = 0;

  for (int i = 0; i < N; i++) {
    if (v[i].second >= k) {
      k = v[i].first;
      answer++;
    }
  }

  cout << answer;
  return 0;
}