#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> visited;

int dfs(int u) {
  visited[u] = true;
  int cnt = 1;
  for(int v : adj[u]) {
    if(!visited[v]) cnt += dfs(v);
  }
  return cnt;
}

int main(){
  int n;
  cin >> n;
  adj.resize(n);
  visited.resize(n, false);
  
  for(int i = 0,a,b; i < n-1; i++) {
    cin >> a >> b;
    --a, --b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  int M = 0;
  for(int i = 1; i <= n; i++) {
    if(!visited[i]) {
      M = max(dfs(i), M);
    }
  }
  return 0;
}
