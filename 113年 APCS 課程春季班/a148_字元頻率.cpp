#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;

bool cmp(pii x, pii y){
    if(x.second == y.second) return (x.first > y.first);
    else return (x.second < y.second);
}

int main(){
    string s;
    while(getline(cin,s)){ //讀取一整行
        map<int,int> mp;
        vector<pair<int,int>> vec;
        for(auto c : s){
            mp[c]++; //計算每個字元出現次數
        } 
        for(auto x : mp){
            vec.push_back(x);
            sort(vec.begin(),vec.end(),cmp); //由大到小排列
        }
        for(auto v : vec){
            cout << v.first << " " << v.second << endl;
        }
        cout << endl;
    }
return 0;
}
