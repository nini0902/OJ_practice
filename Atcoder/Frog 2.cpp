#include <bits/stdc++.h>
using namespace std;

int frog(int n, int k, vector<int> h){
    if(n == 1) return 0;
    vector<int> dp(n,INT_MAX);

    dp[0] = 0;
    dp[1] = abs(h[1]-h[0]);
    if(n < k) k = n;
    for(int i = 2; i < n; i++){
        //要注意加i-j>=0這個條件不然會爆
        for(int j = 1; j <= k && i-j >= 0; j++){
            int f = dp[i-j] + abs(h[i] - h[i-j]);
            dp[i] = min(dp[i], f);
        }
    }
    return dp[n-1];
}

int main(){
    int n,k;
    cin >> n >> k;

    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    cout << frog(n,k,h) << endl;
    return 0;
}
