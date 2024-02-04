#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N,M,S = 0,cnt = 0;
    cin >> N >> M;
    vector<vector<int>> g(N,vector<int>(M,0));
    for(int i = 0; i < N ; i++){
        for(int j = 0; j < M; j++){
            cin >> g[i][j];
        }
        sort(g[i].begin(),g[i].end());
    }
    for(int i = 0; i < N; i++){
        S += g[i][M-1];
    }
    cout << S << endl;
    for(int i = 0; i < N; i++){
        if(S%g[i][M-1]==0){
            if(cnt!=i){
                cout << " ";
            }
            cout << g[i][M-1];
        }
        else{
            cnt += 1;
            if(cnt==N){
                cout << -1;
            }
        }
    }

return 0;
}
