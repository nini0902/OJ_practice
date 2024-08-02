#include <bits/stdc++.h>
typedef unsigned long long int L; 
using namespace std;

bool comp(pair<int,int>& a, pair<int,int>& b){
    //為真的話，a ( 比較小 ) 在前面
    return a.first * b.second < b.first * a.second;
}

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(int i = 0; i < n; i++) cin >> p[i].first; 
    for(int i = 0; i < n; i++) cin >> p[i].second;
    
    sort(p.begin(), p.end(), comp);

    L nw = p[0].first, ans = 0; //nw是紀錄目前第i個(不含)以上的重量
    for(int i = 1; i < n; i++){
        ans += p[i].second * nw; //記錄拿第i個要花多少力氣
        nw += p[i].first; //這裡才把第i個的重量加上去
    }

    cout << ans << endl;

    return 0;
}
