// my answer
// #include <iostream>
// #include <vector>

// using namespace std;

// int main(){
//   int x;
//   vector<int> v;
//   cin >> x;

//   int stick = 64;
//   v.push_back(stick);
//   if(x!=64){
//     while(true){
//       stick/=2;
//       v.pop_back();
//       v.push_back(stick);
//       v.push_back(stick);
//       int sum = 0;
//       for(int i=0; i<v.size()-1; i++){
//         sum+=v[i];
//       }
//       if(sum>=x) v.pop_back();
//       if(sum==x) break;
//     }
//   }
//   cout << v.size();
//   return 0;
// }

#include <iostream>

using namespace std;

int main(){
  int x;
  cin >> x;
  int sum = 0;
  while(x>=1){
    sum += x%2;
    x/=2;
  }
  cout << sum;
  return 0;
}