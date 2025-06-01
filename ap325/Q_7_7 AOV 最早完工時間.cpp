#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<int> w(n+1), indeg(n+1, 0), outdeg(n+1, 0);
  vector<vector<int>> adj(n+1), radj(n+1);
  for(int i = 1; i < n+1; i++) cin >> w[i]; // work time
  for(int i = 0,u,v; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    radj[v].push_back(u);
    indeg[v]++;
    outdeg[u]++;
  }
  
  queue<int> q;
  vector<int> earliest(n+1, 0);
  
  for(int i = 1; i < n+1; i++) {
    if(indeg[i] == 0) {
      q.push(i);
      earliest[i] = 0;
    }
  }
  // earliest project start time
  while(!q.empty()){
    int u = q.front(); q.pop();
    
    for(int v : adj[u]) {
      earliest[v] = max(earliest[u] + w[u], earliest[v]);
      indeg[v]--;
      if(indeg[v] == 0) q.push(v);
    }
  }
  
  int M = 0;
  for(int i = 1; i < n+1; i++){
    M = max(M, earliest[i]+w[i]);
  }
  cout << M << endl;
  
  // project latest start time
  q = queue<int>();
  vector<int> latest(n+1, M);
  
  for(int i = 1; i < n+1; i++) if(outdeg[i] == 0) q.push(i);
  
  while(!q.empty()) {
    int u = q.front(); q.pop();
    latest[u] = min(latest[u], M - w[u]);
    for(int v : radj[u]) {
      latest[v] = min(latest[v], latest[u] - w[v]);
      outdeg[v]--;
      if(outdeg[v] == 0) q.push(v);
    }
  }
  
  for(int i = 1; i < n+1; i++) {
    if(earliest[i] == latest[i]) cout << i << " ";
  }
  cout << endl;
  return 0;
}
