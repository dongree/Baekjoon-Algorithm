// #include <iostream>
// #include <vector>
// #include <cmath>

// using namespace std;

// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);
  
//   vector<int> primeN;
//   for(int i=2; i<1000; i++){
//     bool flag = true;
//     for(int j=2; j<=sqrt(i); j++){
//       if(i%j==0){
//         flag = false;
//         break;
//       }
//     }
//     if(flag) primeN.push_back(i);
//   }

//   while(true){
//     int n;
//     cin >> n;
//     if(n==0) break;
//     for(int i=0; i<primeN.size(); i++){
//       bool flag = true;
//       for(int j=2; j<=sqrt(n-primeN[i]); j++){
//         if((n-primeN[i])%j==0){
//           flag = false;
//           break;
//         }
//       }
//       if(flag){
//         cout << n << " = " << primeN[i] << " + " << n-primeN[i] << '\n';
//         break;
//       }
//     }
//   }


//   return 0;
// }

// another solution 
#include <iostream>
#include <vector>

using namespace std;

bool check[1000001];
vector<int> primeN;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 0; i < 1000001; i++) check[i] = true;
  for(int i=2; i*i <= 1000000; i++){
    if(check[i]){
      for(int j=i*i; j<=1000000; j+=i){
        check[j] = false;
      }
    }
  }

  for(int i=2; i<=1000000; i++){
    if(check[i]) primeN.push_back(i);
  }

  while(true){
    int n;
    cin >> n;
    if(n==0) break;
    for(int i=0; primeN[i]<n; i++){
      int n2 = n-primeN[i];
      if(check[n2]){
        cout << n << " = " << primeN[i] << " + " << n-primeN[i] << '\n';
        break;
      }
    }
  }

  return 0;
}