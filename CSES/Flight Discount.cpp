#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,m;
  cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n+1);
  vector<vector<long long>> dist(n+1, vector<long long>(2, LLONG_MAX));
  
  int a,b,c;
  for(int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    adj[a].push_back({b,c});
  }
  
  dist[1][0] = 0; // 起點
  // pa : (cost, node, used_coupon)
  priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
  pq.push({0,1,0});
  
  while(!pq.empty()) {
    auto [cost, u, used_coupon] = pq.top();
    pq.pop();
    
    if(cost > dist[u][used_coupon]) continue;
    
    for(auto [v,w] : adj[u]) {
      // 不使用折價卷
      if(dist[v][used_coupon] > cost + w) {
        dist[v][used_coupon] = cost + w;
        pq.push({dist[v][used_coupon], v, used_coupon});
      }
      // 如果可以使用折價卷
      if(used_coupon == 0) {
        long long discount = w/2;
        if(dist[v][1] > cost + discount) {
          dist[v][1] = cost + discount;
          pq.push({dist[v][1], v, 1});
        }
      }
    }
  }
  
  cout << dist[n][1] << endl;
  return 0;
}
