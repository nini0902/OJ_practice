#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,D,x,y,sum = 0,io = 1;
    cin >> n >> D >> x;
    for(int i = 1; i < n; i++){
        cin >> y;
        if(io==1){
            if(y >= x+D){
                sum += y-x;
                x = y;
                io = 0;
            }
        }
        else if(io==0){
            if(y <= x-D){
                x = y;
                io = 1;
            }
        }
    }
    cout << sum << endl;
return 0;
}
