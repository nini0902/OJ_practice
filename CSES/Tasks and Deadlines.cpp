#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

bool comp(const pair<LL,LL>& a, const pair<LL,LL> b){
    return a.first < b.first;
}

int main(){
    LL n,used = 0,rw = 0;
    cin >> n;
    vector<pair<LL,LL>> t(n);
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
