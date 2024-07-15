//二分搜
#include <bits/stdc++.h>
using namespace std;

double find_x(double n){
    double l = 0.0001;
    double h = n;
    double mid;
    double t = 1e-12; //精度

    while(h - l > t){ //範圍大於誤差範圍才繼續找
        mid = (l+h) / 2.0;
        double p = pow(mid,mid);

        if(fabs(p-n) < t){
            return mid;
        }
        else if(p < n){
            l = mid;
        }
        else h = mid;
    }
    return (l+h)/2.0;
}

int main(){
    double n;
    cin >> n;
    //輸出設定小數點最多輸出到11位
    cout << fixed << setprecision(11) << find_x(n) << endl;
    return 0;
}Bootstrapping Number
