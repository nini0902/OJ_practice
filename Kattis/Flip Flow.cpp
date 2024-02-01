#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b){
    int* t = a;
    a = b;
    b = t;
    return;
}

int main(){
    int t,s,n,f1 = 0,f,u,d = 0;
    cin >> t >> s >> n;
    u = s;
    cin >> f1;
    for(int i = 0; i < n-1; i++){
        cin >> f;
        u -= f-f1;
        d += f-f1;
        if(u<=0) u = 0,d = s;
        swap(u,d);
        f1 = f;
    }
    if(u-(t-f1)<=0) u = 0;
    else u -= (t-f1);
    cout << u << endl;
return 0;
}
