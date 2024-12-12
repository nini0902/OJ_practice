#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long sum = 0;
    stack<int> st;
    vector<int> p(n+1);
    p[0] = 1e7+1; //先預設第一個人之前那個人超爆高
    st.push(0);

    for(int i = 1; i <= n; i++){
        cin >> p[i];
        while(p[st.top()] <= p[i]){ //如果現在這個太矮
            st.pop(); //就跟他掰掰
        }
        
        sum += (i - st.top()); //第一個人不用加
        st.push(i); //現在這個位置丟進去
    }
    cout << sum << endl;
    return 0;
}
