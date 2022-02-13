// #include <iostream>
// #include <vector>
// #include <string>
// #include <map>

// using namespace std;

// int main(){
//   int t;
//   cin >> t;

//   for(int i=0; i<t; i++){
//     map<string, int> m;
//     vector<string> v;
//     int n, result = 1;
//     cin >> n;
//     for(int j=0; j<n; j++){
//       string name, kind;
//       cin >> name >> kind;
//       m[kind]++;
//       if(m[kind]==1){
//         v.push_back(kind);
//       }
//     }

//     for(string s : m){
//       result*=m[s]+1;
//     }
//     cout << result-1 << '\n';
//   }

//   return 0;
// }

#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
  int t;
  cin >> t;

  for(int i=0; i<t; i++){
    map<string, int> m;
    int n, result = 1;
    cin >> n;
    for(int j=0; j<n; j++){
      string name, kind;
      cin >> name >> kind;
      m[kind]++;
    }

    for(auto s : m){
      result *= (s.second + 1);
    }
    cout << result-1 << '\n';
  }

  return 0;
}