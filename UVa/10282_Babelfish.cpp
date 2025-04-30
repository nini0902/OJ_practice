#include <bits/stdc++.h>
using namespace std;

int main(){
  string code, word, line;
  map<string, string> dic;
  
  while(getline(cin, line)){
    if(line.empty()) break;
    
    istringstream ss(line);
    ss >> word >> code;
    
    dic[code] = word;
  }
  
  while(getline(cin, code)) {
    if(code.empty()) break;
    
    cout << (dic.count(code)? dic[code] : "eh") << endl;
  }
  return 0;
}
