#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main(){
  ifstream fin("planting.in");
  ofstream fout("planting.out");

  int n;
  fin >> n;
  vector<vector<int>> adj(n+1);
  
  for(int i = 0,a,b; i < n-1; i++) {
    fin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  int M = 0;
  for(int i = 1; i <= n; i++) {
    M = max(M, (int)adj[i].size()); // find the one that has the most edges
  }
  
  fout << M+1 << endl;
  return 0;
}
