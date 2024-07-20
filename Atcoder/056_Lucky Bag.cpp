#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,S;
    cin >> N >> S;
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    vector<vector<bool>> dp(N+1,vector<bool>(S+1,false));
    vector<vector<pair<int,char>>> choice(N+1, vector<pair<int,char>>(S+1));
    dp[0][0] = true; 

    for(int i = 1; i <= N; i++){
        //i表示第i天
        for(int j = 0; j <= S; j++){
            //j表示可能累積金額
            //dp[i][j] == true，就是第i天可以所有的取法(每個j表示可達到的金額)
            if(j >= A[i-1] && dp[i-1][j-A[i-1]]){
                dp[i][j] = true;
                choice[i][j] = {j-A[i-1], 'A'}; //前面是儲存第i天取到j元之前的原金額，後面是第i天取的是A
            }
            if(j >= B[i-1] && dp[i-1][j-B[i-1]]){
                dp[i][j] = true;
                choice[i][j] = {j-B[i-1], 'B'}; //前面是儲存第i天取到j元之前的原金額，後面是第i天取的是B
            }
        }
    }

    if(dp[N][S]){
        string s;
        for(int i = N; i > 0; i--){
            s += choice[i][S].second;
            S = choice[i][S].first;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    else cout << "Impossible" << endl;
    return 0;
}
