#include <bits/stdc++.h> 
using namespace std;

int main(){
  int n;
  cin >> n;
  multiset<int> s;
  
  int tower;
  for(int i = 0; i < n; i++){
    cin >> tower;
    auto it = s.upper_bound(tower);
    
    if(it != s.end()) s.erase(it);
    s.insert(tower);
  }
  
  cout << s.size() << endl;
  return 0;
}
