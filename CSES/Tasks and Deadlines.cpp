#include <bits/stdc++.h>
using namespace std;

bool comp(const pair<int,int>& a, const pair<int,int> b){
    return a.first < b.first;
}

int main(){
    int n,used = 0,rw = 0;
    cin >> n;
    vector<pair<int,int>> t(n);
    for(int i = 0; i < n; i++){
        cin >> t[i].first >> t[i].second;
    }
    sort(t.begin(),t.end(),comp);
    
    for(int i = 0; i < n; i++){
        used += t[i].first;
        rw += t[i].second - used;
    }

    cout << rw << endl;
return 0;
}
