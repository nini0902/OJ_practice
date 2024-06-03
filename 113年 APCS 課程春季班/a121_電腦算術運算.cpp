#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    cin >> n;

    while(n--){
        cin >> s;
        stack<int> st;
        bool legal = true;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '(' || s[i] == ',' || s[i] == ')');
            else if(isdigit(s[i])){
                int sum = s[i]-'0';
                while(isdigit(s[++i])){
                    sum = sum * 10 + (s[i]-'0');
                }
                st.push(sum);
                i--; //在判斷while會多做一個（才能使他停下來）
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
                if(s[i+1] != ')') {legal = false; break;}
                int a = st.top(); //a比較晚放所以在上面
                st.pop();
                int b = st.top(); //b比較早放所以在上面
                st.pop();
                //澄清: b是除數，a才是被除數
                if(s[i] == '+') st.push(b+a);
                else if(s[i] == '-') st.push(b-a);
                else if(s[i] == '*') st.push(b*a);
                else if(s[i] == '/' && a == 0) {legal = false; break;}
                else if(s[i] == '/') st.push(b/a);
            }
            else {legal = false; break;}
        }
        if(!legal) cout << -1 << endl;
        else if(st.size() == 1) cout << st.top() << endl;
        else cout << -1 << endl;
    }
return 0;
}
