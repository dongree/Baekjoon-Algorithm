#include <iostream>
#include <stack>

using namespace std;

int main(){
  int k;
  stack<int> st;
  cin >> k;

  int sum = 0;
  for(int i=0; i<k; i++){
    int a;
    cin >> a;
    if(a == 0){
      sum -= st.top();
      st.pop();
    }else{
      st.push(a);
      sum += st.top();
    }
  }
  
  cout << sum;
  return 0;
}