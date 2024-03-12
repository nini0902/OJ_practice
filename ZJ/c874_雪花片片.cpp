#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a(75);
    vector<int> sum(75);
    int n;
    a[0] = 1, sum[0] = 1;
    cin >> n;

    for(int i = 1; i < n; i++){
        int c = 0;
        //用陣列做乘法運算(計算a[i]*4^n-1)
        for(int j = 0; j < 75; j++){
            a[j] = a[j]*4+c; //加上前一位進位的數字
            c = a[j] / 10; //紀錄進位的數
            a[j] = a[j] % 10; // 留下個位數(十位被c紀錄，下次進位)
        }
        //加到sum去
        for(int j = 0; j < 75; j++){
            sum[j] += a[j];
            sum[j+1] += sum[j] / 10;
            sum[j] %= 10;
        }
    }

    bool p = false;
    for(int i = 74; i >=0; i--){
        if(sum[i] || p){ //兩個皆為false(sum為0也就是前面沒意義的數字)不成立
            cout << sum[i];
            p = true; //開始輸出數字
        }
    }
    cout << endl;
return 0;
}
