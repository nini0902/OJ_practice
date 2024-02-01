#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    vector<int> abc(3,0);
    cin >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(),abc.end());
    cout << abc[2]+abc[1] << endl;
return 0;
}
