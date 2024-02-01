#include <bits/stdc++.h>
using namespace std;

int main(){
    unsigned int N,W,l,w,tt = 0;
    cin >> W >> N;
    for(int i = 0; i < N; i++){
        cin >> l >> w;
        tt += l*w;
    }
    cout << tt / W << endl;
}
