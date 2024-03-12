#include <bits/stdc++.h>
using namespace std;

bool even(long long a){
    while(a > 0){
        if((a%10)%2==1) return false;
        a /= 10;
    }
    return true;
}

int main(){
    int n,k;
    cin >> n;
    while(n--){
        cin >> k;
        int s = (int)sqrt(pow(10,k-1)); // 最低範圍 ex, k=5, s = sqrt(10000)
        int e = (int)sqrt(pow(10,k)); // 最高範圍 ex. k=5, e = sqrt(100000)
        for(int i = s; i < e; i++){
            long long a = i*i;
            if(even(a)){
                cout << a << endl;
                break;
            }
        }
    }
return 0;
}
