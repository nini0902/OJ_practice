#include <bits/stdc++.h>
using namespace std;

int main(){
  int tt, kid;
  cin >> tt;
  bool rm = false;
  
  queue<int> q;
  for(int i = 1; i <= tt; i++) q.push(i);
  
  while(!q.empty()){
    kid = q.front();
    q.pop();
    
    if(rm) cout << kid << " ";
    else q.push(kid);
    
    rm = !rm;
  }
  cout << endl;
  return 0;
}
