#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    for(int i = 7; i >= 0; i--){
        if(pow(2,i) <= N){
            cout << pow(2,i) << endl;
            break;
        }
    }
return 0;
}
