#include <bits/stdc++.h>
#include <math.h>
using namespace std;

int t_num(){
    int num = 0,n;
    for(int i = 3; i >= 0; i--){
        cin >> n;
        num += n*pow(10,i);
    }
    return num;
}

int A_F(int a){
    if(a==101) cout << "A";
    else if(a==111) cout << "B";
    else if(a==10) cout << "C";
    else if(a==1101) cout << "D";
    else if(a==1000) cout << "E";
    else if(a==1100) cout << "F";
    return 0;
}

int main(){
    int N,k;
    while(cin>>N){
        for(int j = 0; j < N; j++){
            k = t_num();
            A_F(k);
        }
        cout << endl;
    }
return 0;
}
