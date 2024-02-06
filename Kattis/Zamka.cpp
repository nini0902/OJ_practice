#include <bits/stdc++.h>
using namespace std;

int nm(int i){
    if(i%10==i) return i;
    else if(i%100==i) return i/10 + i%10;
    else if(i%1000==i) return i/100 + (i/10)%10 + i%10;
    else if(i%10000==i) return i/1000 + (i/100)%10 + (i/10)%10 + i%10;
    else return 1;
}

int main(){
    int L,D,X,N,M;
    cin >> L >> D >> X;
    for(int i = L; i <= D; i++){
        if(nm(i)==X){
            cout << i << " ";
            break;
        }
    }
    for(int i = D; i >= L; i--){
        if(nm(i)==X){
            cout << i << endl;
            break;
        }
    }
return 0;
}
