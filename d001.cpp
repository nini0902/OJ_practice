#include <bits/stdc++.h>
using namespace std;

int eval(){
    int val,x,y;
    char c;
    if(cin>>val){
        return val;
    }

    cin.clear();
    cin >> c;

    if(c=='f'){
        x = eval();
        return 2*x-1;
    }
    else if(c=='g'){
        x = eval();
        y = eval();
        return x+2*y-3;
    }
    return 0;
}

int main(){
    cout << eval() << endl;
return 0;
}
