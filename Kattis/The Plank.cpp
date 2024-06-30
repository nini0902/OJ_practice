#include <bits/stdc++.h>
using namespace std;

int plank(int n){
    vector<int> dp(n+1,0);

    dp[1] = 1, dp[2] = 2, dp[3] = 4;
    for(int i = 4; i <= n; i++){
        dp[i] = dp[i-1] + (dp[i-2])*2 + (dp[i-3])*4 - ((dp[i-2])+(dp[i-3])*3);
        //先將以1,2,3放最後的加起來，再扣掉重複的(其實可以簡化怕看不懂就不簡了)
    }

    return dp[n];
}

int main(){
    int n;
    cin >> n;
    cout << plank(n) << endl;
    return 0;
}
