// #include <iostream>

// using namespace std;

// void simplization(int* nu,int* de){
//   bool flag = true;
//   while(flag){
//     bool subFlag = true;
//     for(int i=2; i<=min(*nu,*de); i++){
//       if(*nu%i==0 && *de%i==0){
//         *nu/=i;
//         *de/=i;
//         subFlag = false;
//         break;
//       }
//     }
//     if(subFlag) flag = false;
//   }
// }

// int main(){
//   int a1,a2,b1,b2;
//   cin >> a1 >> a2 >> b1 >> b2;
//   int c2=a2;
//   int d2=b2;
//   while(c2!=d2){
//     if(c2>d2) d2+=b2;
//     else if(c2<d2) c2+=a2;
//   }
//   int result1 = a1*(c2/a2)+b1*(c2/b2);
//   int result2 = c2;
//   simplization(&result1, &result2);
//   cout << result1 << ' ' << result2;
//   return 0;
// }

//유클리드 호제법
#include <iostream>

using namespace std;

int gcd(int a, int b){
  int c;
  while(b!=0){
    c=a%b;
    a=b;
    b=c;
  }
  return a;
}

int main(){
  int a1,a2,b1,b2,result1,result2,gcdd;
  cin >> a1 >> a2 >> b1 >> b2;
  result1 = a1*b2+a2*b1;
  result2 = a2*b2;
  gcdd = gcd(result1, result2);
  cout << result1/gcdd << ' ' << result2/gcdd << '\n';
  return 0;
}