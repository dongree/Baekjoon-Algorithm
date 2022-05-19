#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

char word[100];

int main(){
  int t;
  cin >> t;
  while(t--){
    string s;
    cin >> s;
    int length = s.length();
    for(int i=0; i<length; i++){
      word[i] = s[i];
    }

    int criIdx = length;
    for(int i=length-1; i>0; i--){
      if(word[i-1] < word[i]){
        criIdx=i;
        break;
      }
    }
    if(criIdx==length){
      cout << s << '\n';
      continue;
    }

    for(int i=length-1; i>=criIdx; i--){
      if(word[criIdx-1] < word[i]){
        swap(word[criIdx-1], word[i]);
        break;
      }
    }

    sort(word+criIdx, word+length);

    for(int i=0; i<length; i++){
      cout << word[i];
    }
    cout << '\n';
  }
  return 0;
}

// #include <iostream>
// #include <algorithm>
// #include <string>
// #include <vector>

// using namespace std;

// int main(){
//   int t;
//   cin >> t;
//   while(t--){
//     string s;
//     cin >> s;
//     vector<char> v;
//     for(int i=0; i<s.length(); i++){
//       v.push_back(s[i]);
//     }
//     if(next_permutation(v.begin(), v.end())){
//       for(char c : v){
//         cout << c;
//       }
//     }else{
//       cout << s;
//     }
//     cout << '\n';
//   }
//   return 0;
// }