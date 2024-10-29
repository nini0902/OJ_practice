#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int,int>>> vec;
vector<bool> visited;
int q, cnt = 0;

void dfs(int root){
  visited[root] = true;
  for(auto temp : vec[root]){
    if(visited[temp.first]) continue;
    else if(temp.second < q) continue;
    dfs(temp.first);
    cnt++;
  }
}

int main(){
  int N, V;
  cin >> N >> V >> q;
  
  vec.resize(N+1, vector<pair<int,int>>(0));
  visited.resize(N+1, false);
  
  for(int i = 0,f,t,k; i < N; i++){
    cin >> f >> t >> k;
    vec[f].push_back({t,k});
    vec[t].push_back({f,k});
  }
  
  dfs(V);
  
  cout << cnt << endl;
  return 0;
}
