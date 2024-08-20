#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    long long sum = 0;
    int num, last;
    stack<long long> st;

    st.push(s[0] - '0'); //第一個一定是數字直接push就可以了

    for(int i = 1; i < s.size(); i++){
        if(s[i] == '-'){
            num = s[++i] - '0'; //取下一個數字
            st.push(num * -1); //轉成負數
        }
        else if(s[i] == '+') st.push(s[++i] - '0'); //正數直接丟進就可以了
        else if(s[i] == '*'){
            last = st.top(), st.pop(); //取出上一個數字
            num = s[++i] - '0'; //取下一個數字
            st.push(last * num); //相乘然後丟回去
        }
        else {
            last = st.top(), st.pop(); //取出上一個數字
            num = s[++i] - '0'; //取下一個數字
            st.push(last / num); //相成然後丟回去
        }
    }

    while(!st.empty()){
        num = st.top(), st.pop();
        sum += num;
    }
    cout << sum << endl;
    return 0;
}
