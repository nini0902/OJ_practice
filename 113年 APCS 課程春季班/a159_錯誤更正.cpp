#include <bits/stdc++.h>
#define N 100
using namespace std;
int a[N][N];

int main(){
    int n;
    while(cin >> n){
        if(n == 0) return 0;
        int rs[N] = {0}, cs[N] = {0};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> a[i][j];
                rs[i] += a[i][j]; //計算每個row的總和
                cs[j] += a[i][j]; //計算每個column的總和
            }
        }

        int rcnt = 0, ccnt = 0;
        int ci = -1, cj = -1;
        for(int i = 0; i < n; i++){
            if(rs[i]%2){
                rcnt++; //有row的總和有問題
                ci = i; //計下有問題的row位置
            }
            if(cs[i]%2){
                ccnt++; //有column的總和有問題
                cj = i; //計下有問題的column位置
            }
        }

        if((rcnt==0)&&(ccnt==0)) cout << "OK" << endl;
        else if((rcnt==1)&&(ccnt==1)) cout << "Change bit (" << ci+1 << "," << cj+1 << ")" << endl;
        else cout << "Corrupt" << endl;
    }
return 0;
}
