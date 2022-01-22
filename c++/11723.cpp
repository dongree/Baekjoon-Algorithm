// #include <iostream>
// #include <string>
// #include <vector>

// using namespace std;

// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int m;
//   vector<int> v;
//   cin >> m;

//   for(int i=0; i<m; i++){
//     string s;
//     cin >> s;
//     int x;
//     bool flag = true;
//     if(s=="add"){
//       cin >> x;
//       for(int a : v){
//         if(a==x){
//           flag = false;
//           break;
//         }
//       }
//       if(flag){
//         v.push_back(x);
//       }
//     }
//     else if(s=="remove"){
//       cin >> x;
//       for(int j=0; j<v.size() ;j++){
//         if(v[j]==x){
//           for(int k=j; k<v.size()-1; k++){
//             int temp = v[k];
//             v[k] = v[k+1];
//             v[k+1] = temp;
//           }
//           v.pop_back();
//           break;
//         }
//       }
//     }
//     else if(s=="check"){
//       cin >> x;
//       for(int a : v){
//         if(a==x){
//           flag = false;
//           break;
//         }
//       }
//       if(flag){
//         cout << 0 <<'\n';
//       }else{
//         cout << 1 << '\n';      
//       }
//     }
//     else if(s=="toggle"){
//       cin >> x;
//       for(int j=0; j<v.size() ;j++){
//         if(v[j]==x){
//           for(int k=j; k<v.size()-1; k++){
//             int temp = v[k];
//             v[k] = v[k+1];
//             v[k+1] = temp;
//           }
//           v.pop_back();
//           flag = false;
//           break;
//         }
//       }
//       if(flag){
//         v.push_back(x);
//       }
//     }
//     else if(s=="all"){
//       v = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
//     }
//     else{
//       v = {};
//     }
//   }

//   return 0;
// }

#include <iostream>
#include <string>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  bool set[21] = {false, };
  int m;
  cin >> m;

  for(int i=0; i<m; i++){
    string s;
    cin >> s;
    int x;

    if(s=="add"){
      cin >> x;
      set[x] = true;
    }
    else if(s=="remove"){
      cin >> x;
      set[x] = false;
    }
    else if(s=="check"){
      cin >> x;
      if(set[x]){
        cout << 1 << '\n';
      }else{
        cout << 0 << '\n';
      }
    }
    else if(s=="toggle"){
      cin >> x;
      if(set[x]){
        set[x] = false;
      }else{
        set[x] = true;
      }
    }
    else if(s=="all"){
      for(int j=0; j<21; j++){
        set[j] = true;
      }
    }
    else{
      for(int j=0; j<21; j++){
        set[j] = false;
      }
    }
  }

  return 0;
}