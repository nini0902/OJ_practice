#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,p,c,m,cnt,M,tt;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> p;
        cnt = 1, M = 0, tt = 0;
        for(int j = 0; j < p; j++){
            cin >> c;
            if(c > M){
                cnt = 1;
                M = c;
                m = j+1;
            }
            else if(c==M) cnt = 2;
            tt += c;
        }

         if(cnt > 1) cout << "no winner" << endl;
         else if(M*2 > tt) cout << "majority winner " << m << endl;
         else cout << "minority winner " << m << endl;
    }
    return 0;
}
