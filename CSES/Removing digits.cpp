#include <bits/stdc++.h>
using namespace std;

int remove_dig(int n){
    int cnt = 0;

    while(n > 0){
        int max_dig = 0;
        int temp = n;
        while(temp > 0){
            int digit = temp % 10;
            if(digit > max_dig) max_dig = digit;
            temp /= 10;
        }
        n -= max_dig;
        cnt++;
    }
    return cnt;
}

int main(){
    int n;
    cin >> n;

    cout << remove_dig(n) << endl;
    return 0;
}
