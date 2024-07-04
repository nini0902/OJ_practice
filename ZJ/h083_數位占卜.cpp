#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie();
    int n, ans = 0;
    cin >> n;
    string s[50001];
    set<string> str;

    for(int i = 0; i < n; i++) {
        cin >> s[i];
        str.insert(s[i]);
    }

    for(int i = 0; i < n; i++){
        int len = s[i].size();
        for(int j = 1; j <= len/2; j++){
            //檢查該字串頭尾j個字元是否一樣
            if(s[i].substr(0,j) == s[i].substr(len-j,j)){
                //檢查剩下的字元(j到尾-j範圍內)是否有出現 
                if(str.count(s[i].substr(j,len-j-j))){
                    ans++;   
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
