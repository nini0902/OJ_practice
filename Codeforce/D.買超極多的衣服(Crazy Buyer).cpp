#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n,m,count = 0,cnt = 0;
    cin >> n >> m;
    vector<int> a(n,0);
    for(int i = 0; i < n; i++){
       cin >>  a[i];
       if(a[i]==m){
        cnt += 1;
       }
    }
    for(int i = 0;i < n; i++){
        count = a[i];
        for(int j = i+1; j < n; j++){
            count += a[j];
            if(count==m){
                cnt += 1;
                j = n;
            }
            else if(cnt > m){
                j = n;
            }
        }
    }
   
    cout << cnt << endl;
return 0;
}
