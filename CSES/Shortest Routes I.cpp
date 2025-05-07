#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int, long long>>> graph(n+1);
  vector<long long> dist(n+1, LLONG_MAX);
  dist[1] = 0;
  
  int a,b,c;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    graph[a].push_back({b,c});
  }
  
  priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;
  // pair<long long, int> pair<距離, 節點>
  // vector<pair<long long, int>> 底層容器
  // greater<>> 小的在前
  
  pq.push({0,1}); // 從節點1出發
  while(!pq.empty()) {
    auto [d,u] = pq.top(); pq.pop();
    
    if(d > dist[u]) continue;
    
    for(auto [v, cost] : graph[u]) {
      // 如果經u走到v會更快
      if(dist[v] > dist[u] + cost) {
        dist[v] = dist[u]+cost;
        pq.push({dist[v], v});
      }
    }
  }
  
  for(int i = 1; i <= n; i++) cout << dist[i] << " ";
  cout << endl;
  return 0;
}
