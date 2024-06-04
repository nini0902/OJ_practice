#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    stack<char> st;
    int ans = 0;
    bool corr = true;
    for(int i = 0; i < s.size(); i++){ 
        if(s[i]=='(' ) st.push(s[i]); //碰到"("push進去
        else if(st.empty()){
            corr = false; //遇到")"但沒有"("可以pop表示配對失敗
            break;
        }
        else {
            st.pop(); //碰到")"就pop掉
            ans++;
        }
    }
    if(!st.empty()) corr = false; //裡面還有東西，表示配對失敗
    if(corr) cout << ans << endl;
    else cout << 0 << endl;
return 0;
}
