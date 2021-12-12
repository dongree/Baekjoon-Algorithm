// my answer
// #include <iostream>

// using namespace std;

// int main(){
//   int n, k;
//   int a = 1;
//   int b = 1;

//   cin >> n >> k;

//   for(int i=0; i<k; i++){
//     a *= n-i;
//     b *= k-i;
//   }

//   cout << a/b;
//   return 0;
// }

// way2
// #include <iostream>

// using namespace std;

// int factorial(int n){
//   int value = 1;
//   for(int i=0; i<n-1; i++){
//     value *= n-i;
//   }
//   return value;
// }

// int main(){
//   int n, k, result;

//   cin >> n >> k;

//   result = factorial(n)/(factorial(k)*factorial(n-k));
//   cout << result;
//   return 0;
// }

// <way3>
#include <iostream>

using namespace std;

int factorial(int n){
  if(n==1 || n==0){
    return 1;
  }
  else{
    return n*factorial(n-1);
  }
}

int main(){
  int n, k, result;

  cin >> n >> k;

  result = factorial(n)/(factorial(k)*factorial(n-k));
  cout << result;
  return 0;
}