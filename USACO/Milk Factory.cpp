#include <bits/stdc++.h>
#include <fstream>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);
  ifstream fin("factory.in");
  ofstream fout("factory.out");
  
  int n;
  fin >> n;
  vector<int> in_deg(101), out_deg(101);
  
  for(int i = 0, a,b; i < n-1; i++) {
    fin >> a >> b;
    // a -> b
    out_deg[a]++, in_deg[b]++;
  }
  
  bool encounter_sink = false;
  int ans = -1;
  for(int i = 1; i < n+1; i++) {
    if(encounter_sink && out_deg[i] == 0 && in_deg[i] > 0) {
      ans = -1;
      break; // there're mre than one sink which are impossible to reach each other
    }
    
    if(out_deg[i] == 0 && in_deg[i] > 0) {
      encounter_sink = true; //encountered first sink
      ans = i;
    }
  }
  
  fout << ans << endl;
  return 0;
}
