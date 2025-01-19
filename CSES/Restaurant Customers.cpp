#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<pair<int, int>> vec;
  
  //把同一個人進來跟離開分開為兩個事件
  int in, out;
  for(int i = 0; i < n; i++){
    cin >> in >> out;
    vec.push_back({in, 1}); //將進來視為增加一人
    vec.push_back({out, -1}); //將離開視為減少一人
  }
  
  sort(vec.begin(), vec.end());
  
  //直接走過一遍，邊計算邊找最大
  int cnt = 0, M = 0;
  for(int i = 0; i < n*2; i++){
    cnt += vec[i].second;
    M = max(M, cnt);
  }
  
  cout << M << endl;
  return 0;
}
