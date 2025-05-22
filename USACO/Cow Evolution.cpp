#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<string>> cows;
vector<string> allfeature;

void setIO(string s) {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

// check if there are cows with A, B, AB
bool check(int A, int B) {
  bool AnotB = false, BnotA = false, bothAB = false;
  for(int i = 0; i < n; i++) {
    bool hasA = false, hasB = false;
    // go through all the features of cow[i]
    for(string feature : cows[i]) {
      if(feature == allfeature[A]) {
        hasA = true;
      }
      if(feature == allfeature[B]) {
        hasB = true;
      }
    }
    if(hasA && ! hasB) AnotB = true;
    else if(!hasA && hasB) BnotA = true;
    else if(hasA && hasB) bothAB = true;
  }
  if(AnotB && BnotA && bothAB) return false;
  return true;
}

int main(){
  setIO("evolution");
  cin >> n;
  cows.resize(n);
  
  string s;
  for(int i = 0, m; i < n; i++){
    cin >> m;
    getline(cin, s);
    stringstream ss(s);
    string f;
    while(ss >> f) {
      cows[i].push_back(f);
      // new feature
      if(find(allfeature.begin(), allfeature.end(), f) == allfeature.end()) {
        allfeature.push_back(f);
      }
    }
  }
  
  // go through all the combinations 
  for(int i = 0; i < (int)allfeature.size(); i++) {
    for(int j = i+1; j < (int)allfeature.size(); j++) {
      if(!check(i, j)) {
        cout << "no\n";
        return 0;
      }
    }
  }
  cout << "yes\n";
}
