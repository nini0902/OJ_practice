#include <bits/stdc++.h>
using namespace std;

int main(){
    int m = 0,cnt = 0;
    string s;
    map<string,int> p;
    vector<string> c;
    
    while(getline(cin,s)){ //計算每個候選人的票數
        p[s]++;
        if(p[s]==1) c.push_back(s);
    }

    for(int i = 0; i < c.size(); i++){ //找最高票
        if(p[c[i]] > p[c[m]]){
            m = i;
        }
    }

    for(int i = 0; i < c.size(); i++){ //計算最高票人數(判斷會不會有多個最高票)
        if(p[c[i]]==p[c[m]]) cnt++;
    }

    if(cnt > 1) cout << "Runoff!" << endl;
    else cout << c[m] << endl;
return 0;
}
