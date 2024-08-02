#include <bits/stdc++.h>
using namespace std;
int dir[4] = {0,1,2,3}; //0左、1上、2右、3下
int n, d, step = 1, x,y,ch = 0;

void dir0(vector<vector<int>>& vec){ //向左
    for(int i = 0; i < step; i++){
        cout << vec[x][--y];
    }
    ch = (ch+1)%2; //用來判斷step要不要加一
    if(ch == 0) step += 1;
    d = dir[(d+1)%4];
}

void dir1(vector<vector<int>>& vec){ //向上
    for(int i = 0; i < step; i++){
        cout << vec[--x][y];
    }
    ch = (ch+1)%2;
    if(ch == 0) step += 1;
    d = dir[(d+1)%4];
}

void dir2(vector<vector<int>>& vec){ //向右
    for(int i = 0; i < step; i++){
        cout << vec[x][++y];
    }
    ch = (ch+1)%2;
    if(ch == 0) step += 1;
    d = dir[(d+1)%4];
}

void dir3(vector<vector<int>>& vec){ //向下
    for(int i = 0; i < step; i++){
        cout << vec[++x][y];
    }
    ch = (ch+1)%2;
    if(ch == 0) step += 1;
    d = dir[(d+1)%4];
}

int main(){
    cin >> n >> d;
    vector<vector<int>> vec(n, vector<int>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> vec[i][j];
        }
    }

    x = n/2, y = n/2;
    cout << vec[x][y];
    for(int i = 0; i < (n*2)-1; i++){
        if(i == (n*2)-2) step--;
        if(d == 0) dir0(vec);
        else if(d==1) dir1(vec);
        else if(d==2) dir2(vec);
        else dir3(vec);
    }
    cout << endl;
    return 0;
}
