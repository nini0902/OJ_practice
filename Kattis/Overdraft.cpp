#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n,a,count = 0,s = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a;
        count += a;
        if(count < 0){
            s = max(s,count*-1);
        }
    }
    cout << s << endl;
return 0;
}
