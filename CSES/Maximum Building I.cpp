#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  
  vector<vector<int>> vec(n+2, vector<int>(m+2, 1));
  vector<vector<long long>> h(n+2, vector<long long>(m+2, 0));
  
  string s;
  for(int i = 1; i <= n; i++){
    cin >> s;
    for(int j = 1; j <= m; j++){
      if(s[j-1] == '.') vec[i][j] = 0;
      else vec[i][j] = 1;
      
      //計算每個位置的最大高度
      if(vec[i][j] == 1) continue;
      if(i == 1) h[i][j] = 1;
      else if(vec[i-1][j] == 0) h[i][j] = (h[i-1][j]+1);
      else h[i][j] = 1;
    }
  }
  
  long long M = 0;
  for(int i = 1; i <= n; i++){
    stack<long long> st;
    for(int j = 1; j <= m; j++){
      //跟Advertisement差不多的概念
      while(!st.empty() && h[i][st.top()] > h[i][j]){
        long long H = h[i][st.top()];
        st.pop();
        long long W = st.empty()? j-1 : j-st.top()-1;
        M = max(M, H*W);
      }
      st.push(j);
    }
    //處理剩下的元素
    while(!st.empty()){
      long long H = h[i][st.top()];
      st.pop();
      long long W = st.empty()? m:m-st.top();
      M = max(M, H*W);
    }
  }
  
  cout << M << endl;
  
  return 0;
}
