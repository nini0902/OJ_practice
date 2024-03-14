#include <bits/stdc++.h>
using namespace std;
int sq[65536], so, num[4];

void s(int r, int id){
    if(id == 3){
        int n = sqrt(r);
        if(sq[n] == r){
            so++;
            num[3] = n;
            cout << num[0] << " " << num[1] << " " << num[2] << " " << num[3];
        }
        return;
    }
    //窮舉可能的數字
    int lb = 1;
    if(id > 0){
        lb = num[id-1];
    }
    int ub = sqrt(r/(4-id));
    for(int n = lb; n <= ub; n++){
        num[id] = n;
        s(r-sq[n], id+1);
    }
}

int main(){
    for(int i = 1; i < 65536; i++){
        sq[i] = i*i;
    }
    int k;
    cin >> k;
    so = 0;
    s(1 << k, 0);
    if(so == 0) cout << 0 << endl;

return 0;
}
