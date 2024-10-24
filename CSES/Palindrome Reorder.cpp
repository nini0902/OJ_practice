#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  vector<pair<char, int>> vec(26);
  for(int i = 0; i < s.length(); i++){
    vec[s[i]-65].first = s[i];
    vec[s[i]-65].second++;
  }
  
  stack<pair<char,int>> st;
  int cnt_mid = 0;
  for(int i = 0; i < 26; i++){
    if(vec[i].second%2 == 1){
      cnt_mid++;
    }
  }
  
  char mid;
  //超過一個字母出現奇數次不可能組成回文
  if(cnt_mid > 1) cout << "NO SOLUTION" << endl;
  else{
    for(int i = 0; i < 26; i++){
      if(vec[i].second%2 == 1){
        cnt_mid = vec[i].second;
        mid = vec[i].first;
        continue;
      }
      else{
        //利用stack的FILO性質，反向儲存
        for(int j = 0; j < vec[i].second/2; j++) cout << vec[i].first;
        st.push({vec[i].first, vec[i].second/2});
      }
    }
    
    for(int i = 0; i < cnt_mid; i++) cout << mid;
    
    //反向輸出後段，與前面相對成為迴文
    while(!st.empty()){
      auto it = st.top();
      st.pop();
      for(int i = 0; i < it.second; i++) cout << it.first;
    }
  }
  return 0;
}
