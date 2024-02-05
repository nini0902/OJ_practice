#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,n,y1,y2,Y;
    bool OK;
    cin >> N;
    while(N--){
        cin >> n;
        cin >> y1 >> y2;
        OK = 1;
        Y = abs(y1-y2);
        for(int i = 0; i < n-1; i++){
            cin >> y1 >> y2;
            if(Y != (y1-y2)) OK = 0;
        } 
        if(OK) cout << "yes" << endl;
        else cout << "no" << endl;
        if(N) cout << endl;
    }
return 0;
}
