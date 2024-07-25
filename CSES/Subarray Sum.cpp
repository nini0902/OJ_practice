#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a, nf = 0;
    cin >> n;
    long long arr[n+1] = {}, dp[n+2] = {0}, M = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    dp[0] = arr[0];
    for(int i = 1; i < n; i++){
        dp[i] = dp[i-1]+arr[i];
        while(dp[i] - arr[nf] > dp[i]) {dp[i]-=arr[nf]; nf++;}
        M = max(M, dp[i]);
    }

    cout << M << endl;
    return 0;
}
