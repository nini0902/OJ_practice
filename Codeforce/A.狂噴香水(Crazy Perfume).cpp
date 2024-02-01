#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,cnta = 0,cntb = 0,a,b;
    char A,B;
    cin >> n;
    for(int i = 0; i < n; i++){
        if(cin>>a);
        else{
            cin.clear();
            cin >> A;
            if(A=='J') a = 11;
            else if(A=='Q') a = 12;
            else if(A=='K') a = 13;
        }
        if(cin>>b);
        else{
            cin.clear();
            cin >> B;
            if(B=='J') b = 11;
            else if(B=='Q') b = 12;
            else if(B=='K') b = 13;
        }

        if(a>b) cntb += abs(a-b);
        else cnta += abs(a-b);
    }

    cout << cnta << " " << cntb << endl;
return 0;
}
