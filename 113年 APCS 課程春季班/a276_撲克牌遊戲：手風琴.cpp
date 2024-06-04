#include <bits/stdc++.h>
using namespace std;
#define N 52
void move(vector<stack<string>> &, int);
bool run;

bool check(vector<stack<string>> &v, int a, int b){
    if(b < 0) return false;
    string ca = v[a].top();
    string cb = v[b].top();
    if(ca[0] == cb[0]) return true; //點數相同
    if(ca[1] == cb[1]) return true; //花色相同
    return false;
}

void merge(vector<stack<string>> &v, int a, int b){
    run = true;
    v[b].push(v[a].top());
    v[a].pop();
    if(v[a].empty()) v.erase(v.begin()+a);
    move(v,b);
}

void move(vector<stack<string>> &v, int i){
    if(i == v.size()) return;
    if(check(v,i,i-3)) merge(v,i,i-3);
    else if(check(v,i,i-1)) merge(v,i,i-1);
    else move(v,i+1);
}

int main(){
    string s;
    while(cin >> s){
        if(s == "#") break;
        vector<stack<string>> v(N);
        v[0].push(s); //將牌先放進去
        for(int i = 1; i < N; i++){
            cin >> s;
            v[i].push(s);
        }
        run = true; //假設遊戲可以繼續進行
        while(run){
            run = false;
            move(v,1); //檢查最上面的牌
        }
        string str = (v.size() == 1)? " pile remaining: ":" piles remaining: ";
        cout << v.size() << str;
        for(auto &x: v){
            cout << x.size() << " ";
        }
        cout << endl;
    }
return 0;
}
