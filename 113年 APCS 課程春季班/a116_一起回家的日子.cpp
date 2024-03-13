#include <bits/stdc++.h>
using namespace std;

//判斷是否為閏年
bool ly(int y){
    if(((y%4==0)&&(y%100!=0))||(y%400==0)){
        return true;
    }
    else return false;
}

int main(){
    int n, y, m, d, x, a;
    int md[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};
    char c;
    cin >> n >> a;

    //找最小公倍數
    while(--n){
        cin >> x;
        a = a*x/__gcd(a,x);
    }

    cin >> y >> c >> m >> c >> d;
    d += a;
    
    //計算一起回家的準確天數
    md[2] = (ly(y))?29:28; // ? if_true : else false
    while(d > md[m]){
        d -= md[m];
        if(m==12){
            y++;
            m = 1;
            md[2] = (ly(y))?29:28;
        }
        else m++;
    }

    cout << y << "/";
    if(m <= 9) cout << "0";
    cout << m << "/";
    if(d <= 9) cout << "0";
    cout << d << endl;;
return 0;
}
