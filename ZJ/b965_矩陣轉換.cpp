#include <iostream>
#include <vector>
using namespace std;

void rotate(int R, int C, vector<vector<int>>& B,vector<vector<int>>& B1){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            B1[C-1-j][i] = B[i][j];
        }
    }
}
void flip(int R, int C, vector<vector<int>>& B){
    for(int i = 0; i < R/2; i++){
        for(int j =  0; j < C; j++){
            int temp = B[i][j];
            B[i][j] = B[R-1-i][j];
            B[R-1-i][j] = temp;
        }
    }
}
void cin_B(int R, int C, vector<vector<int>>& B){
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C; j++){
            cin >> B[i][j];
        }
    }
}
void print_B(int R,int C,vector<vector<int>>& B){
    cout << R <<" "<< C << endl;
    for(int i = 0; i < R;i++){
        for(int j = 0; j < C; j++){
            cout << B[i][j];
            if(j!=C-1){
                cout<<" ";
            }
        }
    cout << endl;
    }
}
int main(){

    int R,C,M;
    while(cin >> R >> C >> M){
        if(R==0 && C==0){
            break;
        }
    

    vector<vector<int>> B(11,vector<int>(11,0));
    vector<vector<int>> B1(11,vector<int>(11,0));
    cin_B(R,C,B);

    vector<int> m(M,0);
    for(int i = 0; i < M; i++){
        cin >> m[i];
    }

    int count = 0;
    for(int i = M-1; i>=0;i--){
        if(m[i]==0){
            if(count==0){
                rotate(R,C,B,B1);
                count = 1;
            }
            else{
                rotate(C,R,B1,B);
                count = 0;
            }
        }
        if(m[i]==1){
            if(count==0){
                flip(R,C,B);
            }
            else{
                flip(C,R,B1);
            }
        }
    }
    
    if(count==0){
        print_B(R,C,B);
    }
    else{
        print_B(C,R,B1);
    }
    }
    
return 0;    
}
