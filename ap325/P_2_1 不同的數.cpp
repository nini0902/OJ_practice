#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<int> s;
  
  int num;
  while(n--){
    cin >> num;
    s.insert(num);
  }
  
  cout << s.size() << endl;
  for(auto i : s) cout << i << " ";
  cout << endl;
  return 0;
}
