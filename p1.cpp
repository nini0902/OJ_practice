#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,p,m,k,d,sit,stand = 0,s;
    cin >> n >> p >> m >> k >> d;
    if(n-p<=0){
        sit = 0;
        stand = p-n;
    }
    else sit = n-p;

    sit += m;
    stand -= k;
    
    if(sit-stand>=d){
        cout << "Happy :>" << endl;
        cout << sit-stand-d << endl;
    }
    else{
        cout << "Sad :((" << endl;
        cout << stand  + d-1 - sit << endl;
    }

return 0;
}