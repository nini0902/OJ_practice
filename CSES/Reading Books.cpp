#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, book, tt = 0, longest = 0;
    cin >> n;
    while(n--){
        cin >> book;
        tt += book;
        longest = max(longest, book);
    }
    //情況1：最長的書 > 其他的書加總(總時間就是兩個人分別讀完最長的加總)
    //情況2：最長的書 < 其他的書加總(總時間就是讀完所有的書的加總)
    cout << max(longest*2, tt) << endl;
    return 0;
}
