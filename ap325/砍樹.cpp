#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, l;
    int tt = 0, H = 0;
    cin >> n >> l;
    vector<int> p(n+2);
    vector<int> h(n+2);
    stack<int> st;

    p[0] = 0, p[n+1] = l;
    st.push(0);
    for(int i = 1; i <= n; i++) cin >> p[i];
    for(int i = 1; i <= n; i++) cin >> h[i];

    for(int i = 1; i <= n; i++){
        if(p[i] - h[i] >= p[st.top()] || p[i] + h[i] <= p[i+1]){
            tt += 1; //可以砍的樹又多一個
            H = max(H, h[i]);

            //檢查前面的樹可不可以砍
            while(st.size() > 1 && p[st.top()] + h[st.top()] <= p[i+1]){
                tt += 1;
                H = max(H, h[st.top()]);
                st.pop();
            }
        }
        else st.push(i); //不能砍只能直接push進去
    }

    cout << tt << endl;
    cout << H << endl;
    return 0;
}
