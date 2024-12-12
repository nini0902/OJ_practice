#include <bits/stdc++.h>
using namespace std;

int c(char ch){
    switch(ch){
        case '(': return 1;
        case ')': return -1;

        case '[': return 2;
        case ']': return -2;

        case '{': return 3;
        case '}': return -3;
    }
    return 0;
}

int main(){
    string s;
    int n; //n表示括號的種類：1 = ()；2 = []；3 = {}

    while(cin >> s){
        stack<int> q;
        for(int i = 0; i < s.size(); i++){
            n = c(s[i]);
            
            if(!q.empty()){ //裡面有東西
                if(q.top() + n == 0 && n < 0){
                    q.pop();
                }
                else q.push(n);
            }
            else q.push(n);
        }
        
        if(q.empty()) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    return 0;
}
