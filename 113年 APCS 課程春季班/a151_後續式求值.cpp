#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){ //讀入整行
        stack<int> st;

        for(int i = 0; i < s.size(); i++){
            if(isdigit(s[i])) st.push(s[i]-'0'); //判斷如果是數字
            else{
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                if(s[i] == '+') st.push(b+a);
                else if(s[i]=='-') st.push(b-a);
                else if(s[i]=='*') st.push(b*a);
                else if(s[i]=='/') st.push(b/a);
                else if(s[i]=='%') st.push(b%a); 
            }
        }
        cout << st.top() << endl;
    }
return 0;
}
