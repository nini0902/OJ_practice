#include <bits/stdc++.h>
using namespace std;

int eval(){
    int val,x,y,z;
    char c;
    if(cin>>val) return val;
    cin.clear();
    cin >> c;
    if(c=='f'){
        x = eval();
        return 2*x-3;
    }
    else if(c=='g'){
        x = eval();
        y = eval();
        return 2*x+y-7;
    }
    else if(c=='h'){
        x = eval();
        y = eval();
        z = eval();
        return 3*x-2*y+z;
    }
    return 0;
}

int main(){
    cout << eval() << endl;
    return 0;
}
