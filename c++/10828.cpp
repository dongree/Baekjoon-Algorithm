// 1. stack solution
// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;

// int main(){
//   int n;
//   stack<int> st;
//   cin >> n;

//   for(int i=0; i<n; i++){
//     string s;
//     cin >> s;
//     if(s=="push"){
//       int a;
//       cin >> a;
//       st.push(a);
//     }
//     else if(s=="pop"){
//       if(st.empty()){
//         cout << -1 << '\n';
//       } else{
//         cout << st.top() << '\n';
//         st.pop();
//       }
//     }
//     else if(s=="size"){
//       cout << st.size() << '\n';
//     }
//     else if(s=="empty"){
//       cout << st.empty() << '\n';
//     }
//     else if(s=="top"){
//       if(st.empty()){
//         cout << -1 << '\n';
//       }else{
//         cout << st.top() << '\n';
//       }
//     }
//   }
//   return 0;
// }

// 2. vector solution
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
  vector<int> v;
  int n;

  cin >> n;

  for(int i=0; i<n; i++){
    string s;
    cin >> s;
    if(s=="push"){
      int a;
      cin >> a;
      v.push_back(a);
    }
    else if(s=="pop"){
      if(v.empty()){
        cout << -1 << '\n';
      }else{
        cout << v.back() << '\n';
        v.pop_back();
      }
    }
    else if(s=="size"){
      cout << v.size() << '\n';
    }
    else if(s=="empty"){
      cout << v.empty() << '\n';
    }
    else if(s=="top"){
      if(v.empty()){
        cout << -1 << '\n';
      }else{
        cout << v.back() << '\n';
      }
    }
  }

  return 0;
}