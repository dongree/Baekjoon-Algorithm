// #include <iostream>
// #include <algorithm>
// #include <vector>
// #include <map>

// using namespace std;

// int arr[1000000];
// map<int, int> m;
// vector<int> v;

// int main(){
//   int n;
//   cin >> n;
//   for(int i=0; i<n; i++){
//     cin >> arr[i];
//     v.push_back(arr[i]);
//   }

//   sort(v.begin(),v.end());

//   int k=0;
//   for(int i=0; i<n; i++){
//     if(m.find(v[i]) != m.end()) continue;
//     m.insert({v[i],k});
//     k++;
//   }

//   for(int i=0; i<n; i++){
//     cout << m[arr[i]] << ' ';
//   }
//   return 0;
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v1;
vector<int> v2;

int main(){
  int n;
  cin >> n;
  int a;
  for(int i=0; i<n; i++){
    cin >> a;
    v1.push_back(a);
    v2.push_back(a);
  }

  sort(v1.begin(),v1.end());
  v1.erase(unique(v1.begin(), v1.end()),v1.end());

  for(int i=0; i<n; i++){
    cout << lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin() << ' ';
  }
  return 0;
}