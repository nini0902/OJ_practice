#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> vec(n);
  
  for(int i = 0,a,b,c; i < m; i++) {
    cin >> a >> b >> c;
    vec[a].push_back({b,c});
    vec[b].push_back({a,c});
  }
  
  priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
  vector<int> dist(n, INT_MAX);
  dist[0] = 0;
  pq.push({0,0}); // start
  
  while(!pq.empty()) {
    // d : current dist, u : currnet point
    auto [d, u] = pq.top(); pq.pop();
    if(d > dist[u]) continue;
    
    for(auto [v,w] : vec[u]){
      if(dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v});
      }
    }
  }
  
  int M = 0, unreachable = 0;
  for(int i = 1; i < n; i++) {
    if(dist[i] == INT_MAX) {unreachable++; continue;}
    M = max(M, dist[i]);
  }
  
  cout << M << "\n" << unreachable << "\n";
  return 0;
}
