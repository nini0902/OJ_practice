#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
  ifstream fin("revegetate.in");
  ofstream fout("revegetate.out");
  
  int n;
  fin >> n;
  vector<vector<int>> to(n+1);
  
  int a,b;
  while(fin >> a >> b) {
    to[b].push_back(a);
  }
  
  for(int i = 1; i < n+1; i++) {
    if(to[i].size() == n-1) {
      fout << i << endl;
      break;
    }
    if(i == n) fout << "-1\n" << endl;
  }
  return 0;
}
