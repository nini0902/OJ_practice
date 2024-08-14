#include <bits/stdc++.h>
using namespace std;
string s;

long long f(int l, int r){
    long long mn = LLONG_MAX, mx = LLONG_MIN;
    long long tt = 1, add = 0, num = 0;

    for(int i = l; i <= r; i++){
        if(s[i] == ','){
            tt *= (add+num); //將前面數字有乘的先乘好
            mn = min(mn, tt);
            mx = max(mx, tt);
            tt = 1, add = 0, num = 0; //乘、加、數字重置
        }
        else if(s[i] == '*'){
            tt *= add+num;
            add = 0, num = 0;
        }
        else if(s[i] == '+'){
            add += num;
            num = 0;
        }
        else if(s[i] == 'f'){
            int cnt = 0, fr; //fr是計算這個f函數到哪裡
            for(int j = i+1; j <= r; j++){
                if(s[j] == '(') cnt++;
                else if(s[j] == ')') {
                    cnt--;
                    if(cnt == 0) {fr = j; break;}
                }
            }
            num = f(i+2, fr-1);
            i = fr;
        }
        else {
            num *= 10;
            num += s[i] - '0';
        }
    }
    tt *= add + num;
    mn = min(mn, tt);
    mx = max(mx, tt);
    return mx-mn;
}

int main(){
    cin >> s;
    s += ',';
    cout << f(0, s.length()-1) << endl;
    return 0;
}
