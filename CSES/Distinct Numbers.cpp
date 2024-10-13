#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  set<long long> s;
  long long a;
  for(int i = 0; i < n; i++){
    cin >> a;
    s.insert(a);
  }
  cout << s.size() << endl;
  return 0;
}
