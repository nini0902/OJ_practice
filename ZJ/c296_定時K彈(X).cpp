#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M,K,cntM = 0,cntK = 0,i = 1;
    cin >> N >> M >> K;
    vector<vector<int>> g(N+1,vector<int>(1,0));
    g[0][0] = -1;
    while(cntK!=K){
        if(g[i][0]==0){
            cntM+=1;
        }
        if(cntM==M){
            g[i][0]=-1;
            cntM = 0;
            cntK += 1;
        }
        i++;
        if(i > N){
            i = 1;
        }
    }
    for(int j = 0; j < N; j++){
        if(g[j][0]==0){
            cout << j << endl;
        }
    }
return 0;
}
