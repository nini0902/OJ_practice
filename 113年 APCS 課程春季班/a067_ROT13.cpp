#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        for(auto c : s){ //auto是自動根據s的特性設定自己的特性
            if(isupper(c)){
                cout << (char)((c-'A'+13)%26 + 'A'); //如果是大寫
            }
            else if(islower(c)){
                cout << (char)((c-'a'+13)%26 + 'a'); //如果是小寫
            }
            else{
                cout << c; //其餘的符號直接輸出
            }
        }
    }
    return 0;
}
