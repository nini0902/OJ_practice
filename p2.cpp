#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,M,K,W,Q,cnt = 0,s1,s2,w1,w2;
    cin >> N >> M >> K >> W >> Q;
    vector<vector<int>> p(N,vector<int>(M+K+1,0));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> p[i][j];
        }
    }
    for(int i = 0; i < N; i++){
        for(int j = M; j < M+K; j++){
            cin >> p[i][j];
            p[i][M+K] += p[i][j];
        }
    }

    for(int i = 0; i < Q; i++){
        cin >> s1 >> w1 >> s2 >> w2;
        auto it = find(p[s1-1].begin(),p[s1-1].begin()+M, s2);
        if(it != p[s1-1].begin()+M){
            cout << "Yes ";

            auto a1 = find(p[s1-1].begin(), p[s1-1].end(), w1);
            auto b1 = find(p[s2-1].begin(), p[s2-1].end(), w2);
            if(a1 != p[s1-1].end() && b1 != p[s2-1].end()){
                int a = distance(p[s1-1].begin(), a1);
                int b = distance(p[s2-1].begin(), b1);

                p[s1-1][a] = w2;
                p[s2-1][b] = w1;

                p[s1-1][M+K] -= w1;
                p[s1-1][M+K] += w2;
                p[s2-1][M+K] -= w2;
                p[s2-1][M+K] += w1;
            }
        }
        else{
            cout << "No ";
        }

        for(int i = 0; i < N; i++){
            if(p[i][M+K]>W) cnt += K;
        }
        cout << cnt << endl;
        cnt = 0;
    }

return 0;

}