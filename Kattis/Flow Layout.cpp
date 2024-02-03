#include <bits/stdc++.h>
using namespace std;

int main(){
    int m = 1,r,c,rm,mc,ml,cl,t;
    while(m){
        cin >> m;
        rm = m; // 設定好長度
        ml = 0,mc = 0,cl = 0,t = 1;
        while(t&&m){
            //輸入方塊長寬
            cin >> r >> c;
            //假設放不下
            if((rm - r < 0)||(r==-1&&c==-1)){
                ml = max(ml,m-rm);
                rm = m;
                cl += mc;
                mc = 0;
            }
            if(r!=-1&&c!=-1){
                rm -= r;
                mc = max(mc,c);
            }
            else t = 0;
        }
        if(m==0);
        else cout << ml << " x " << cl << endl;
    }
return 0;
}
