#include <bits/stdc++.h>
using namespace std;

//檢查 s2 的前 s1.size() 個數字是否跟 s1 一樣
bool is_pre(const string& s1, const string& s2){
  return s1 == s2.substr(0, s1.size());
}

int main(){
  int n,m;
  cin >> n;
  
  while(n--){
    cin >> m;
    vector<string> phone(m);
    
    for(int i = 0; i < m; i++) cin >> phone[i];
    sort(phone.begin(), phone.end());
    
    bool not_pre = true;
    for(int i = 0; i < m-1; i++){
      if(is_pre(phone[i], phone[i+1])) {
        cout << "NO" << endl;
        not_pre = false;
        break;
      }
    }
    if(not_pre) cout << "YES" << endl;
  }
  return 0;
}
