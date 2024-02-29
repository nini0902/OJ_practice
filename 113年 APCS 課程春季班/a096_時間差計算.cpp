#include <bits/stdc++.h>
using namespace std;

int main(){
    int H,M,S,h1,h2,m1,m2,s1,s2;
    string t1,t2,h = "0",m = "0",s = "0";
    cin >> t1 >> t2;

    h1 = int(t1[0]-48)*10+int(t1[1]-48);
    m1 = int(t1[3]-48)*10+int(t1[4]-48);
    s1 = int(t1[6]-48)*10+int(t1[7]-48);

    h2 = int(t2[0]-48)*10+int(t2[1]-48);
    m2 = int(t2[3]-48)*10+int(t2[4]-48);
    s2 = int(t2[6]-48)*10+int(t2[7]-48);
    
    H = h2-h1, M = m2-m1, S = s2-s1;

    if(H < 0) H += 24;
    if(M < 0) M += 60, H -= 1;
    if(H < 0) H += 24;
    if(S < 0) S += 60, M -= 1;
    if(M < 0) M += 60, H -= 1;
    if(H < 0) H += 24;

    if(H < 10) h = h + to_string(H);
    else h = to_string(H);
    if(M < 10) m = m + to_string(M);
    else m = to_string(M);
    if(S < 10) s = s + to_string(S);
    else s = to_string(S);

    cout << h << ":" << m << ":" << s << endl;
return 0;
}
