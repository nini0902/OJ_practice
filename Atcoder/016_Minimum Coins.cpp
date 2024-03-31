#include <bits/stdc++.h>
using namespace std;

int C(int N, int a, int b, int c) {
    int min_count = N;
    for (int i = 0; i <= N / a; ++i) {
        for (int j = 0; j <= (N - a * i) / b; ++j) {
            int k = (N - a * i - b * j) / c;
            if (a * i + b * j + c * k == N) {
                min_count = min(min_count, i + j + k);
            }
        }
    }
    return min_count;
}

int main(){
    int N;
    vector<int> abc(3);
    cin >> N >> abc[0] >> abc[1] >> abc[2];
    sort(abc.begin(),abc.end());
    cout << C(N,abc[2],abc[1],abc[0]) << endl;
    
return 0;
}
