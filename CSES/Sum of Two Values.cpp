#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, int>> vec;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    int n,t = 1;
    long long x,a;
    cin >> n >> x;
    int l = 0, r = n-1;

    for(int i = 1; i <= n; i++){
        cin >> a; //輸入數據
        vec.push_back(make_pair(a,i));
    }
    sort(vec.begin(),vec.end());

    while(t){
        if(vec[l].first + vec[r].first == x){
            cout << vec[l].second << " " << vec[r].second << " ";
            t = 0;
        }
        else if(vec[l].first + vec[r].first > x){
            r--;
        }
        else if(vec[l].first + vec[r].first < x){
            l++;
        }
        if(l >= r) cout << "IMPOSSIBLE" << endl, t = 0;
    }
return 0;
}
