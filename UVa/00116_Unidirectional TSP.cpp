//DP
#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
LL n,m;

vector<vector<LL>> w; //儲存每個格子的重量
vector<vector<bool>> dp; //檢查是否能轉移
vector<vector<pair<LL, LL>>> choice; //紀錄目前狀量以及上一個格子
pair<LL, LL> lu, ld, l; //前次轉移(左上、左下、正左)

int main(){
    
    while(cin >> m >> n){
        if(m<1 || m>10 || n<1 || n>100) break;

        w.resize(11, vector<LL>(101,0));
        dp.resize(11, vector<bool>(101, false));
        choice.resize(11, vector<pair<LL, LL>>(101, {LONG_MAX, 0}));


        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> w[i][j];
            }
        }
        
        for(int i = 0; i < m; i++){
            choice[i][0] = {w[i][0], i};
            dp[i][0] = true;
        }

        for(int i = 1; i < n; i++){
            for(int j = 0; j < m; j++){
                if(dp[(j+m-1)%m][i-1] == true){ //從左上角轉移
                    dp[j][i] = true; //這個位置設為有走過
                    lu = {choice[(j+m-1)%m][i-1].first + w[j][i], (j+m-1)%m};
                }
                else lu = {LONG_MAX, -1};

                if(dp[(j+m+1)%m][i-1] == true){ //從左下角轉移
                    dp[j][i] = true;
                    ld = {choice[(j+m+1)%m][i-1].first + w[j][i], (j+m+1)%m};
                }
                else ld = {LONG_MAX, -1};

                if(dp[j][i-1] == true){ //從正左方轉移
                    dp[j][i] = true;
                    l = {choice[j][i-1].first + w[j][i], j};
                }
                else l = {LONG_MAX, -1};
                
                choice[j][i] = min(lu, min(ld,l)); //預設是比較first的內容
            }
        }
        
        LL M = 0, mi = LONG_MAX;
        for(int i = 0; i < m; i++){
            if(choice[i][n-1].first < mi){
                mi = choice[i][n-1].first;
                M = i;
            }
        } 
        
        LL pre = M;
        string s;
        for(int i = n-1; i >= 0; i--){
            s += to_string(pre+1);
            if(i != 0) s += " ";
            pre = choice[pre][i].second;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
        cout << choice[M][n-1].first << endl;
    }
    return 0;
}
