#include <bits/stdc++.h>
using namespace std;

int find_path(vector<string>& s, int n){
    vector<vector<int>> dp(n,vector<int>(n,0));

    dp[0][0] = (s[0][0] == '.') ? 1:0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '#') continue;
            if(i+1 < n && s[i+1][j] == '.') {
                dp[i+1][j] += dp[i][j];
            }
            if(j+1 < n && s[i][j+1] == '.') {
                dp[i][j+1] += dp[i][j];
            }
        }
    }
    return dp[n-1][n-1];
}

int main(){
    int n;
    cin >> n;
    vector<string> s(n);

    for(int i = 0; i < n; i++) cin >> s[i];

    cout << find_path(s,n) << endl;
return 0;
}
