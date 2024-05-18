#include <bits/stdc++.h>
#define N 5
using namespace std;
int a[N];
bool found, used[N];

void dfs(int id, int result){
    if(found) return;
    if(id == N){
      //滿足總和為
        if(result == 23){
            cout << "Possible" << endl;
            found = true;
        }
        return;
    }
    for(int i = 0; i < N; i++){
        if(!used[i]){
            used[i] = true;
            //每種運算都去嘗試
            dfs(id+1, result+a[i]);
            dfs(id+1, result*a[i]);
            dfs(id+1, result-a[i]);
            //每種排列都去嘗試
            used[i] = false;
        }
    }
}
int main(){
    while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]){
        if(count(a,a+5,0) == 5) break; //結束
        memset(used, 0, sizeof(used));
        found = false;
        //一組一組去試
        for(int i = 0; i < N; i++){
            used[i] = true;
            dfs(1,a[i]);
            used[i] = false;
            if(found) break;
        }
        if(!found) cout << "Impossible" << endl;
    }
    return 0;
}
