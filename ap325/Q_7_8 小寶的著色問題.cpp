#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<int>>& adj, vector<int>& color, int start) {
  if(color[start] == -1) color[start] = 0; // set start to blue
  queue<int> q;
  q.push(start);
  
  while(!q.empty()) {
    int u = q.front(); q.pop();
    for(int v : adj[u]) {
      if(color[v] == -1) {
        color[v] = 1-color[u];
        q.push(v);
      }
      // find the same color in the neighbor
      else if(color[v] == color[u]) return false;
    }
  }
  return true;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int T;
  cin >> T;
  
  while(T--) {
    int n,m;
    cin >> n >> m;
    if(m == 0) {
      cout << "yes\n";
      continue;
    }
    vector<vector<int>> adj(n);
    for(int i = 0,a,b; i < m; i++) {
      cin >> a >> b;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    
    vector<int> color(n, -1); // 0 for blue, 1 for red 
    bool ans = true;
    for(int i = 0; i < n; i++) {
      if(color[i] == -1) {
        if(!check(adj, color, i)) {ans = false; break;}
      }
    }
    
    if(ans == true) cout << "yes\n";
    else cout << "no\n";
  }
  return 0;
}
