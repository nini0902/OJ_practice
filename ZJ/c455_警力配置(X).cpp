#include <iostream>
#include <vector>
#include <map>
using namespace std;

int find_max(map<int,int> &x){
    int max = 0;
    int max_x;
    for(const auto& i : x){
        if(i.second > max){
            max = i.second;
            max_x = i.first;
        }
    }
    return max_x;
}

int main(){
    int p,q,k,a,t = 0,max_x,max_y,xt,yt,count_p = 0,count = 0;
    cin >>a;
    cin >>p>>q>>k;
    vector<vector<int>> G(k,vector<int>(3,0));
    map<int,int> x;
    map<int,int> y;
    for(int i = 0; i < k; i++){
        cin >> G[i][1];
        G[i][0] = 0;
        x[G[i][1]] += 1;
        cin >> G[i][2];
        y[G[i][2]] += 1;
    }

    for(int j = 0; j < k; j++){
        max_x = find_max(x);
        xt = x[max_x];
        max_y = find_max(y);
        yt = y[max_y];
        count = 0;
        if(xt>=yt){
            for(int i = 0; i < k; i++){
                if(G[i][1]==max_x){
                    x[max_x] -= 1;
                    y[G[i][2]] -= 1;
                    G[i][0] = 1;
                    t = 1;
                }
            }
            if(t){
                count_p += 1;
                t = 0;
            }
        }
        else if(yt>xt){
            for(int i = 0; i < k; i++){
                if(G[i][2]==max_y){
                    x[G[i][1]] -= 1;
                    y[max_y] -= 1;
                    G[i][0] = 1;
                    t = 1;
                }
            }
            if(t){
                count_p += 1;
                t = 0;
            }
        }
        for(int i = 0; i < k; i++){
            if(G[i][0]==1){
                count += 1;
            }
        }
        if(count == k){
            break;
        }
    }

    cout << count_p << endl;
    
return 0;
}
