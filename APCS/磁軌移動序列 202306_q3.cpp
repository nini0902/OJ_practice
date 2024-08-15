#include <bits/stdc++.h>
using namespace std;
int i = 0;
string s;

long long cal(int &head, int &tail){
    long long tt = 0, t;
    head = tail = -1;
    while(1){
        if(i >= s.length()) return tt;

        if(s[i] == 'T'){
            t = (s[i+1]-'0')*10 + s[i+2]-'0';
            i += 3;
            if(tail < 0) head = t; //表示是第一個數字
            else tt += abs(tail - t); //加上距離
            tail = t; //尾更新成新的
        }
        else if(s[i] == 'L'){
            t = s[i+1] - '0'; //計算迴圈次數
            i += 2;
            int h,e; //記錄迴圈內的頭跟尾
            long long cost = cal(h,e); //計算迴圈一次的距離
            if(tail < 0) head = h; //只有一圈，haed更新成迴圈的頭(其實也就只有一個數字)
            else tt += abs(tail - h); //計算迴圈前到迴圈第一個數字的差
            tail = e; //更新結尾
            tt += cost*t + abs(h-e)*(t-1); //迴圈內的距離 * 迴圈次數；頭跟尾的差只會返回t-1次
        }
        else {
            i += 1;
            return tt;
        }
    }
}


int main() {
    int i,j;
    cin >> s;
    cout << cal(i,j) <<endl;
    return 0;
}
