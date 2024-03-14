#include <bits/stdc++.h>
using namespace std;

void d(double& p1, double& p2){
    if(p1 == p2) p2 = p1/2;
}

int main(){
    double p1, p2;
    cout << "Original price:" << endl;
    cin >> p1 >> p2;
    d(p1,p2);
    cout << "Price after discount:" << endl;
    cout << p1 << " " << p2 << endl;

return 0;
}
