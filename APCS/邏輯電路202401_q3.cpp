#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,p,q,r,m;
  cin >> p >> q >> r >> m;
  n = p+q+r; //total nodes(input+gate+output)
  
  vector<int> data(n+1), gate(n+1, 0), d(n+1, 0);
  // input signal
  for(int i = 1; i <= p; i++) {
    cin >> data[i];
  }
  // input the gate type
  for(int i = p+1; i <= p+q+1; i++) {
    cin >> gate[i];
  }
  
  vector<int> in_deg(n+1, 0);
  // out and in neighbor
  vector<vector<int> to(n+1), from(n+1);
  for(int i = 0,u,v; i < m; i++) {
    cin >> u >> v;
    indeg[v]++;
    to[u].push_back(v);
    from[v].push_back(u);
  }
  
  vector<int> seq;
  // put the inputs(indeg == 0) in
  for(int i = 1; i <= p; i++) seq.push_back(i);
  int head = 0;
  while(head < seq.size()) {
    int v = seq[head]; head++;
    for(int u : to[v]) {
      indeg[u]--;
      if(indeg[u] == 0) seq.push_back(u);
    }
  }
  assert(seq.size() == n);
  
  for(int i = p+1; i < n; i++) {
    int g = seq[i];
    if(gate[g] == 1) { // AND
      data[g] = data[from[g][0]] & data[from[g][1]];
      d[g] = max(d[from[g][0]], d[from[g][1]])+1;
    }
    else if(gate[g] == 2) { //OR
      data[g] = data[from[g][0]] | data[from[g][1]];
      d[g] = max(d[from[g][0]], d[from[g][1]])+1;
    }
    else if(gate[g] == 3){ //XOR
      data[g] = data[from[g][0]] ^ data[from[g][1]];
    }
  }
  return 0;
}
