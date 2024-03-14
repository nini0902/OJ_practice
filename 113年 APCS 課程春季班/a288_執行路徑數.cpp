#include <bits/stdc++.h>
using namespace std;

long long d(string t){ //t為終止條件
    string s;
    long long ways = 1, w = 0;
    while(cin >> s){
        if(s==t) break; //碰到終止條件即停止
        if(s == "IF"){
            w = d("ELSE");
            w += d("END_IF");
            ways *= w;
        }
    }
    return ways;
}

int main(){
    int n;
    cin >> n;
    while(n--){
        cout << d("ENDPROGRAM") << endl;
    }
return 0;
}
