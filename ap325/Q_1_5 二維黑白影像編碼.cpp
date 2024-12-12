#include <bits/stdc++.h>
using namespace std;
string s;

int cnt1(int& a,int n){
    a++;
    if(s[a]=='0') return 0;
    else if(s[a]=='1') return n*n;
    else return cnt1(a,n/2) + cnt1(a,n/2) + cnt1(a,n/2) + cnt1(a,n/2);
}
int main(){
    int n;
    cin >> s >> n;
    int a = -1;
    cout << cnt1(a,n) << endl;
return 0;
}
