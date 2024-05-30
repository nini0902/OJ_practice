#include <bits/stdc++.h>
using namespace std;
#define MX 30000
#define N 5
unsigned long long w[MX+1] = {1};

int main(){
    int n;
    int v[N] = {1,5,10,25,50};
    for(int i = 0; i < N; i++){ //假定目前最後一個放v[i]元
        for(int j = v[i]; j <= MX; j++){
            w[j] += w[j-v[i]]; //假定j元最後一個放v[i],則加上w[j-v[i]]的方法數即為j的方法數
        }
    }
    while(cin >> n){
        if(w[n] == 1) cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else cout << "There are " << w[n] << " ways to produce " << n << " cents change." << endl;
    }
return 0;
}
