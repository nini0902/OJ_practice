#include <bits/stdc++.h>
using namespace std;
#define N 10001

int main(){
    int n;
    while(cin >> n && n){
        while(1){ //不知道會有幾筆測資
            int b[N];
            cin >> b[1];
            if(b[1]==0) break;
            for(int i = 2; i <= n; i++){
                cin >> b[i]; //B站
            }
            stack<int> st;
            int g = 1; //計算現在符合到B站的第幾輛車
            for(int i = 1; i <= n; i++){
                if(i != b[g]) st.push(i); //如果不符，先進休息站排隊
                else g++;
                while(!st.empty() && st.top() == b[g]){ //如果休息站的車可以出來
                    st.pop();
                    g++;
                }
            }
        if(!st.empty()) cout << "No" << endl;
        else cout << "Yes" << endl;
        }
        cout << endl;
    }
return 0;
}
