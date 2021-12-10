// My answer<way1>
// #include <iostream>
// #include <string>

// using namespace std;

// int main(){
//   int n, result;
//   cin >> n;

//   string s = to_string(n);
//   int size = s.size();
  
//   for(int i = n-9*size; i <= n-size; i++){
//     result = 0;
//     s = to_string(i);
//     for(int j=0; j<s.size(); j++){
//       result += (s[j]-'0');
//     }
//     result += i;
//     if(result == n){
//       cout << i;
//       return 0;
//     }
//   }
//   cout << 0;
  
//   return 0;
// }

// another answer<way2> 
#include <iostream>

using namespace std;

int soulution(int a){
  int sum = a;
  while(a){
    sum += (a%10);
    a /= 10;
  }

  return sum;
}

int main(){
  int n, sum;
  cin >> n;
  
  for(int i = 0; i <= n; i++){
    sum = soulution(i);
    if(sum == n){
      cout << i;
      return 0;
    }
  }
  cout << 0;
  
  return 0;
}