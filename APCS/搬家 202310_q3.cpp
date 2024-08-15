#include <bits/stdc++.h>
using namespace std;
int visited[501][501] = {0}; //儲存這個位置是否檢查過

bool west(char c){ //可通西
    return c == 'X' || c == 'H' || c == '7' || c == 'J';
}
bool east(char c){ //可通東
    return c == 'X' || c == 'H' || c == 'L' || c == 'F';
}
bool north(char c){ //可通北
    return c == 'X' || c == 'I' || c == 'L' || c == 'J';
}
bool south(char c){ //可通南
    return c == 'X' || c == 'I' || c == '7' || c == 'F';
}

int main(){
    int n,m,x,y;
    string s[501];
    cin >> m >> n;
    for(int i = 0; i < m; i++) cin >> s[i]; //一次讀入一整行
    int M = 0;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(s[i][j] == '0' || visited[i][j]) continue; //造訪過或為0就跳過

            vector<pair<int,int>> vec;
            int head = 0;
            vec.push_back({i,j});
            visited[i][j] = 1;
            while(head < vec.size()){
                int r = vec[head].first, c = vec[head].second;
                head++;
                //檢查這個點的四個方向有沒有可以通的
                if(c < n-1 && !visited[r][c+1] && east(s[r][c]) && west(s[r][c+1])){
                    vec.push_back({r,c+1});
                    visited[r][c+1] = 1;
                }
                if(c > 0 && !visited[r][c-1] && west(s[r][c]) && east(s[r][c-1])){
                    vec.push_back({r,c-1});
                    visited[r][c-1] = 1;
                }
                if(r < m-1 && !visited[r+1][c] && south(s[r][c]) && north(s[r+1][c])){
                    vec.push_back({r+1,c});
                    visited[r+1][c] = 1;
                }
                if(r > 0 && !visited[r-1][c] && north(s[r][c]) && south(s[r-1][c])){
                    vec.push_back({r-1,c});
                    visited[r-1][c] = 1;
                }
            }
            M = max(M, (int)vec.size());
        }
    }
    cout << M << endl;
    return 0;
}
