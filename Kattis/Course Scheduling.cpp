#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  cin.ignore();
  
  map<string, set<string>> mp;
  string s;
  
  for(int i = 0; i < n; i++){
    getline(cin, s);
    size_t pos = s.find_last_of(' ');
    string name = s.substr(0, pos);
    string course = s.substr(pos+1);

    mp[course].insert(name);
  }
  
  for(const auto& p : mp){
    cout << p.first << " " << mp[p.first].size() << endl;
  }
  return 0;
}
