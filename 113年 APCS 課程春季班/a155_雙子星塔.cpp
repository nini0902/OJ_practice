#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2, cnt = 1;
    
    while(cin >> n1 >> n2){
        if(n1 == 0 && n2 == 0) break;
        int t1[n1+1], t2[n2+1];
        vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

        for(int i = 1; i <= n1; i++) cin >> t1[i];
        for(int j = 1; j <= n2; j++) cin >> t2[j];

        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                //i是t1第i個，j是t2第j個
                if(t1[i] == t2[j]) dp[i][j] = dp[i-1][j-1]+1; //這組可以保存，所以延續上一組+1
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]); //選要麼沒有t1[i]要麼沒有t2[j]
            }
        }
        
        cout << "Twin Towers #" << cnt++ << endl;
        cout << "Number of Tiles : " << dp[n1][n2] << endl;
    }
    return 0;
}
