// my solution
// #include <iostream>
// #include <string>
// #include <stack>

// using namespace std;

// int main(){

//   while(true){
//     string s;
//     getline(cin, s);
//     if(s == "."){
//       break;
//     }
//     stack<char> st;
//     for(int i=0; i< s.length(); i++){     
//       if(st.empty()){
//         if(s[i] == '(' || s[i] == '[' || s[i] == ')' || s[i] == ']'){
//           st.push(s[i]);
//         }
//       }else{
//         if(s[i] == '(' || s[i] == '[' ){
//           st.push(s[i]);
//         }
//         else if((st.top() == '(' && s[i] == ')') || (st.top() == '[' && s[i] == ']')){
//           st.pop();
//         } 
//         else if((st.top() == '(' && s[i] == ']') || (st.top() == '[' && s[i] == ')')){
//           st.push(s[i]);
//         } 
//       }
//     }
    
//     if(st.empty()){
//       cout << "yes" << '\n';
//     } else{
//       cout << "no" << '\n';
//     }
//   }

//   return 0;
// }

// another solution
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(){

  while(true){
    string s;
    getline(cin, s);
    if(s == "."){
      break;
    }
    stack<char> st;
    bool flag = true;
    for(int i=0; i< s.length(); i++){   
      if(s[i] == '(' || s[i] == '[' ){
        st.push(s[i]);
      }
      else if(s[i] == ')'){
        if(!st.empty() && st.top() == '('){
          st.pop();
        }else{
          flag = false;
          break;
        }
      }
      else if(s[i] == ']'){
        if(!st.empty() && st.top() == '['){
          st.pop();
        }else{
          flag = false;
          break;
        }
      }
    }
    
    if(flag && st.empty()){
      cout << "yes" << '\n';
    } else{
      cout << "no" << '\n';
    }
  }

  return 0;
}

