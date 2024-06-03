#include <bits/stdc++.h>
using namespace std;

int main(){
    map<char, int> mp;
    mp['+'] = 1;
    mp['-'] = 1;
    mp['*'] = 2;
    mp['/'] = 2;
    string s;
    cin >> s;
    stack <char> st;

    for(int i = 0; i < s.size(); i++){
        if(s[i]=='(') st.push(s[i]);
        else if(s[i]==')'){
            while(st.top()!='('){
                cout << st.top(); //把這組括號內的東西都印出來
                st.pop();
            }
            st.pop(); //這個'('也要拿掉
        }
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
            while(!st.empty() && mp[st.top()] >= mp[s[i]]){
                cout << st.top(); //輸出運算符號
                st.pop();
            }
            st.push(s[i]);
        }
        else { //是A~Z
            cout << s[i];
        }
    }
    while(!st.empty()) cout << st.top(), st.pop();
return 0;
}
