#include <bits/stdc++.h>
using namespace std;
int N;
bool found;
bool used[10];
bool check(int x){
    bool xused[10] = {0};
    if(x < 10000 && used[0] == 1) return false; //第一位為0且被用過
    if(x < 10000) xused[0] = true;

    while(x > 0){
        int d = x%10;
        if(xused[d]) return false;
        if(used[d]) return false;
        xused[d] = true; //fghij設定為已用過
        x /= 10;
    }
    return true;
}

void dfs(int abcde, int id){
    if(id >= 5){
        if(abcde%N != 0) return; //不能整除
        int fghij = abcde / N;
        if(fghij < 1234) return;
        if(check(fghij)){
            found = true;
            cout << abcde << " / ";
            if(fghij < 10000) cout << 0;
            cout << fghij << " = " << N << endl;;
            return; 
        }
    }
    //窮舉所有可能
    for(int i = 0; i < 10; i++){
        if(used[i]) continue;
        used[i] = true;
        dfs(abcde * 10 + i, id+1);
        used[i] = false;
    }
}

int  main(){
    while(cin >> N){
        if(N==0) break;
        memset(used, 0, sizeof(used)); //初始化
        found = false;
        dfs(0,0);
        if(!found) cout << "There are no solutions for " << N << "." << endl;
        cout << endl;
    }
return 0;
}
