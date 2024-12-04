#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  multiset<int> h;
  vector<int> t(m);
  for(int i = 0,x; i < n; i++) {cin >> x; h.insert(x);}
  for(int i = 0; i < m; i++) cin >> t[i];
  
  for(int i = 0; i < m; i++){
    auto it = h.upper_bound(t[i]); //找到第一個大於目標的票價
    if(it == h.begin()) cout << -1 << " "; //找不到
    else {--it; cout << *it << " "; h.erase(it);} //減一就是答案，賣過的票就不能用，所以要擦掉
  }
  cout << endl;
  return 0;
}
