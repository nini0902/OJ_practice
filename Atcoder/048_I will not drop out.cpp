#include <bits/stdc++.h>
typedef long long LL;
using namespace std;

bool comp(LL a, LL b){
    return a > b;
}

int main(){
    LL n,k,cnt = 0;
    cin >> n >> k;
    vector<LL> s;
    for(int i = 0,a,b; i < n; i++){
        cin >> a >> b;
        s.push_back(b);
        s.push_back(a-b);
    }
    sort(s.begin(),s.end(),comp);
    for(int i = 0; i < k; i++) cnt += s[i];
    cout << cnt << endl;
return 0;
}
