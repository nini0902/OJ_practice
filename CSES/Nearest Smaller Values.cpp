#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  vector<int> vec(n+1);
  for(int i = 1; i < n+1; i++) cin >> vec[i];
  
  stack<int> st;//儲存左邊所有小於當前值的位置
  st.push(0);
  for(int i = 1; i <= n; i++){
    while(!st.empty() && vec[st.top()] >= vec[i]) st.pop();
    cout << st.top() << " ";
    st.push(i);
  }
  return 0;
}
