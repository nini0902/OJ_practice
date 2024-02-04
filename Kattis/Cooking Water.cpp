#include <bits/stdc++.h>
using namespace std;

int main(){
    int N,a,b,m = 1000, M = 0;
    vector<int> T(1000);
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a >> b;
        M = max(M,b), m = min(m,a);
        for(int j = a; j < b+1; j++) T[j]++;
    }

    for(int i = m; i < M+1; i++){
        if(T[i]==N){
            cout << "gunilla has a point" << endl;
            break;
        }
        else if(i==M) cout << "edward is right" << endl;
    }
return 0;
}
