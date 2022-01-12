// my answer
// #include <iostream>
// #include <vector>

// using namespace std;

// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int n;
//   vector<int> nCard(20000000);
//   cin >> n;
//   for(int i=0; i<n; i++){
//     int a;
//     cin >> a;
//     nCard[a+10000000]++;
//   }
//   int m;
//   cin >> m;
//   for(int i=0; i<m; i++){
//     int b;
//     cin >> b;
//     cout << nCard[b+10000000] << ' ';
//   }

//   return 0;
// }

// another answer
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  int m;
  cin >> m;
  for(int i=0; i<m; i++){
    int a;
    cin >> a;
    auto l = lower_bound(v.begin(), v.end(), a);
    auto u = upper_bound(v.begin(), v.end(), a);
    cout << u-l << ' ';
  }
}