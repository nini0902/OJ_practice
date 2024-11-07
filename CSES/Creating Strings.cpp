#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  
  vector<string> vec;
  sort(s.begin(), s.end()); //string 要先排序
  
  do{
    vec.push_back(s);
  }while(next_permutation(s.begin(), s.end()));
  
  cout << vec.size() << endl;
  for(string str : vec) cout << str << endl;
  return 0;
}
