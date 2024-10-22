#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  
  queue<int> q1, q2;
  
  if(n%4 == 0){
    for(int i = 1; i <= n; i++){
      if(i%4 == 1 || i%4 == 0) q1.push(i);
      else q2.push(i);
    }
  }
  else if(n%4 == 3){
    q1.push(1); 
    q1.push(2);
    q2.push(3);
    for(int i = 4; i <= n; i++){
      if(i%4 == 0 || i%4 == 3) q1.push(i);
      else q2.push(i);
    }
  }
  
  if(n%4 != 0 && n%4 != 3) cout << "NO" << endl;
  else {
    cout << "YES" << endl;
    cout << q1.size() << endl;
    while(!q1.empty()) {cout << q1.front() << " "; q1.pop();}
    cout << endl;
    cout << q2.size() << endl;
    while(!q2.empty()) {cout << q2.front() << " "; q2.pop();}
    cout << endl;
  }
  return 0;
}
