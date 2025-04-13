#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n;
  map<string, int> mp;
  set<string> S;
  
  string s;
  for(int i = 0; i < n; i++){
    cin >> s;
    S.insert(s);
    mp[s]++;
  }
  
  cin >> m;
  for(int i = 0; i < m ; i++){
    cin >> s;
    S.insert(s);
    mp[s]--;
  }
  
  int ans = 0;
  for(string str : S){
    ans = max(ans, mp[str]);
  }
  
  cout << ans << endl;
  return 0;
}
