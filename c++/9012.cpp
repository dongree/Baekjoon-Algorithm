#include <iostream>
#include <string>

using namespace std;

int main(){
  int t, count;
  cin >> t;

  for(int i=0; i<t; i++){
    string s;
    cin >> s;
    count = 0;
    for(char c : s){
      if(c == '('){
        count +=1;
      }
      else if(c== ')'){
        count -=1;
      }
      if(count < 0){
        break;
      }
    }
    if(count == 0){
      cout << "YES" << '\n';
    }else{
      cout << "NO" << '\n';
    }
  }
  return 0;
}

// stack solution

// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;

// int main(){
//   int t;
//   cin >> t;
  
//   for(int i=0; i<t; i++){
//     string s;
//     cin >> s;
//     stack<char> stack;
//     for(char c : s){
//       if(stack.empty() || c == '('){
//         stack.push(c);
//       }
//       else if(stack.top() == '('){
//         stack.pop();
//       }
//     }
//     if(stack.empty()){
//       cout << "YES" << '\n';
//     } else{
//       cout << "NO" << '\n';
//     }
//   }

//   return 0;
// }