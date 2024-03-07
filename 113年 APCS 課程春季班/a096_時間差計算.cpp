#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,m,s,t1,t2,dif;
    char ch;
    cin >> h >> ch >> m >> ch >> s;
    t1 = h*3600 + m*60 + s;

    cin >> h >> ch >> m >> ch >> s;
    t2 = h*3600 + m*60 + s;

    dif = (86400+t2-t1)%86400;

    cout << setw(2) << setfill('0') << dif/3600 << ":" 
         << setw(2) << setfill('0') << dif/60%60 << ":" 
         << setw(2) << setfill('0') << dif%3600%60 << endl;
return 0;
}
