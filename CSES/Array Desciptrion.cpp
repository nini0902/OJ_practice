#include <bits/stdc++.h>
using namespace std;

int count_arr(int n, int m, vector<int>& x){
    vector<int> dp(n, 0);
    dp[0] = 1;

    int cnt = 0;
    for(int i = 1; i < n; i++){
        cnt = 0;
        if(x[i-1] == 0){
            if(abs(x[i-2]+1-x[i]) == 1) cnt++;
            if(x[i-2] == x[i]) cnt++;
            if(abs(x[i-2]-1-x[i]) == 1) cnt++;
            dp[i] = dp[i-1]*cnt;
        }
        else dp[i] = dp[i-1];
    }
    return dp[n-1];
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> x(n);
    for(int i = 0; i < n; i++) cin >> x[i];
    cout << count_arr(n,m,x) << endl;

    return 0;
}
