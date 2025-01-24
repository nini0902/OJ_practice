#include <bits/stdc++.h>
using namespace std;

int main(){
  ios::sync_with_stdio(false);
	cin.tie(NULL);
	
  int n, m;
  cin >> n >> m;
  
  multiset<int, greater<int>> len; //gaps between lights
  set<int> light; //traffic lights
  
  light.insert(0);
  light.insert(n);
  len.insert(n);
  
  for(int i = 0, l; i < m; i++){
    cin >> l;
    
    auto a = light.upper_bound(l); //first light to the right
    auto b = prev(a); //first light to the left
    
    len.erase(len.find(*a - *b)); //erase the gap between a and b
    //add new gaps
    len.insert(*a - l); 
    len.insert(l - *b);
    
    light.insert(l); //add new light
    cout << *len.begin() << endl; //print the longest gap
  }
  return 0;
}
