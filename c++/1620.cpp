// #include <iostream>
// #include <string>
// #include <map>

// using namespace std;

// int main(){
//   ios_base::sync_with_stdio(false);
//   cin.tie(NULL);
//   cout.tie(NULL);

//   int n, m;
//   cin >> n >> m;
//   map<string, int> book1;
//   map<int, string> book2;

//   for(int i=1; i<n+1; i++){
//     string name;
//     cin >> name;
//     book1[name] += i;
//     book2[i] = name;
//   }

//   for(int i=0; i<m; i++){
//     string input;
//     cin >> input;
//     if(input[0] - '0' <= 9){
//       cout << book2[stoi(input)] << '\n';
//     } else{
//       cout << book1[input] << '\n';
//     }
//   }

//   return 0;
// }

#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;
  map<string, int> book1;
  vector<string> book2 = {"zero"};

  for(int i=1; i<n+1; i++){
    string name;
    cin >> name;
    book1[name] += i;
    book2.push_back(name);
  }

  for(int i=0; i<m; i++){
    string input;
    cin >> input;
    if(input[0] - '0' <= 9){
      cout << book2[stoi(input)] << '\n';
    } else{
      cout << book1[input] << '\n';
    }
  }

  return 0;
}