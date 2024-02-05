#include <bits/stdc++.h>
using namespace std;

int main(){
    int p,m = 0, m1;
    vector<int> c(6,0);
    for(int j = 1; j < 6; j++){
        for(int i = 1; i < 5; i++){
            cin >> p;
            c[j] += p;
        }
    }

    for(int i = 1; i < 6; i++){
        if(c[i] > m){
            m = c[i];
            m1 = i;
        }
    }
    cout << m1 << " " << m << endl;
    return 0;
}
