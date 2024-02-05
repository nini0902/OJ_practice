#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,g;
    cin >> n;
    g = n-1;
    for(int i = 1; i < n*2; i+=2){
        for(int j = 0; j < g; j++) cout << " ";
        for(int j = 0; j < i; j++) cout << "*";
        cout << endl;
        g--;
    }
    return 0;
}
