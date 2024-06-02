#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    map<string, map<string, int>> m; //map<地點, map<動物,數量>>
    vector< pair<string, vector<string>> > v;
    string animal, p;
    int num;
    while(n--){
        cin >> animal >> num >> p;
        if(m.count(p) == 0) v.push_back({p, {animal}}); //p沒出現過
        else if(m[p].count(animal) == 0){ //動物在p沒出現過
            for(auto &x:v){
                if(x.first == p){
                    x.second.push_back(animal);
                    break;
                }
            }
        }
        m[p][animal] += num;
    }
    for(auto x : v){
        cout << x.first << ":";
        bool comma = false;
        for(auto y : x.second){
            if(comma) cout << ",";
                cout << y << " " << m[x.first][y];
                comma = true;
        }
        cout << endl;
    }
return 0;
}
