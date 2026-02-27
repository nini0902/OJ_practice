#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
  LL N, K, cnt = 0;
  cin >> N >> K;
  vector<LL> prev(N, -1),next(N, -1),sb(N, -1);
  set<pair<LL,LL>> S;
  
  for(int i = 0; i < N; i++) {
    cin >> sb[i];
    prev[i] = i-1;
    if(i < N-1) next[i] = i+1;
    S.insert({sb[i], i}); //排序沙包數量
  }
  
  while(!S.empty()){
    auto it = S.begin();
    LL x = it -> first; // 沙包數量
    int y = it -> second; // 座標
    
    if(x > K) break; // 超出最大附載量
    S.erase(it);
    
    cnt += x;
    
    int p = prev[y];
    int j = next[y];
    
    if(j != -1){
      S.erase({sb[j], j});
      sb[j] += x;
      S.insert({sb[j], j});
    }
    
    if(p != -1) next[p] = j;
    if(j != -1) prev[j] = p;
    
    sb[y] = 0;
  }
  
  cout << cnt << endl;
  return 0;
}
