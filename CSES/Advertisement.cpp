#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  
  stack<long long> st;
  vector<long long> h(n);
  
  long long M = 0;
  for(int i = 0; i < n; i++) cin >> h[i];
  
  for(int i = 0; i < n; i++){
    //維護一個遞增序列(上一個數字就是離自己最近比自己矮的)
    while(!st.empty() && h[st.top()] > h[i]){
      long long height = h[st.top()];
      st.pop();
      long long w = (st.empty())? i : i-st.top()-1; //當前高度可延伸到上一個位置+1~當前位置
      M = max(M, height*w);
    }
    st.push(i);
  }
  //最後還有剩記得要計算
  while(!st.empty()){
      int height = h[st.top()];
      st.pop();
      int w = (st.empty())? n : n-st.top()-1;
      M = max(M, height*w);
  }
  
  cout << M << endl;
  return 0;
}
