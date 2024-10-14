#include <bits/stdc++.h>
#define N 500010
using namespace std;
vector<int> vec[N];
vector<int> cnt;

void dfs(int root){
  for(int k : vec[root]){
    dfs(k);
    cnt[root] += (cnt[k]+1);
  }
}

int main(){
  int n;
  cin >> n;
  
  cnt.resize(n+1, 0);
  int boss;
  for(int i = 2; i <= n; i++){
    cin >> boss;
    vec[boss].push_back(i);
  }
  
  dfs(1);
  
  for(int i = 1; i <= n; i++){
    cout << i << ":" << cnt[i] << endl;
  }
  
  return 0;
}
