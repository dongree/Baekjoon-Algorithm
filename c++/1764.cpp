// my answer
// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int main(){
//   int n, m;
//   cin >> n >> m;

//   vector<string> nh;
//   vector<string> nhs;

//   for(int i=0; i<n; i++){
//     string a;
//     cin >> a;
//     nh.push_back(a);
//   }
//   sort(nh.begin(), nh.end());

//   for(int i=0; i<m; i++){
//     string b;
//     cin >> b;
//     int start = 0;
//     int end = n-1;
//     while(start<=end){
//       int mid = (start+end)/2;
//       if(nh[mid] == b){
//         nhs.push_back(b);
//         break;
//       }
//       else if(nh[mid] < b){
//         start = mid+1;
//       }
//       else{
//         end = mid-1;
//       }
//     }
//   }
//   sort(nhs.begin(), nhs.end());
//   cout << nhs.size() << '\n';
//   for(string s : nhs){
//     cout << s << '\n';
//   }

//   return 0;
// }

// another answer

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(){

  int n, m;
  cin >> n >> m;
  map<string, int> dic;

  vector<string> v;
  for(int i=0; i<n+m; i++){
    string s;
    cin >> s;
    dic[s]++;
    if(dic[s] > 1){
      v.push_back(s);
    }
  }
  sort(v.begin(), v.end());

  cout << v.size() << '\n';
  for(string s : v){
    cout << s << '\n';
  }
  return 0;
}
