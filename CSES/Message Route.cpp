#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, m;
  cin >> n >> m;
  
  vector<vector<int>> vec(n+1);
  vector<int> dis(n+1, -1), p(n+1, -1);
  queue<int> q; //for bfs
  
  for(int i = 0,a,b; i < m; i++){
    cin >> a >> b;
    vec[a].push_back(b);
    vec[b].push_back(a);
  }
  
  q.push(1); //start
  dis[1] = 0;
  while(!q.empty()){
    int u = q.front();
    q.pop();
    
    for(auto v : vec[u]){
      if(dis[v] == -1){ //尚未訪問
        dis[v] = dis[u] + 1;
        p[v] = u; //紀錄途徑
        q.push(v); 
      }
    }
  }
  
  if(dis[n] == -1) cout << "IMPOSSIBLE" << endl;
  else{
    vector<int> path;
    for(int cur = n; cur != -1; cur = p[cur]) path.push_back(cur);
    reverse(path.begin(), path.end());
    
    cout << dis[n]+1 << endl;
    for(int node : path) cout << node << " ";
    cout << endl;
  }
  
  return 0;
}
