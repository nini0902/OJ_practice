#include <bits/stdc++.h>
using namespace std;

//自定義雜湊函數
struct custom_hash {
  size_t operator()(int x) const{
    return x ^ (x >> 16);
  }
};

int main(){
  int n;
  cin >> n;
  
  unordered_map<int,int, custom_hash> mp;
  int a, cnt = 0, start = 0;
  for(int i = 0; i < n; i++){
    cin >> a;
    
    if(mp.count(a) && mp[a] >= start){
      start = mp[a]+1;
    }
    mp[a] = i;
    cnt = max(cnt, i-start+1);
  }
  cout << cnt << endl;
  return 0;
}
