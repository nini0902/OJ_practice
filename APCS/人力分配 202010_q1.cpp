#include <bits/stdc++.h>
using namespace std;

int main() {
    int A1, B1, C1, A2, B2, C2, n;
    cin >> A1 >> B1 >> C1 >> A2 >> B2 >> C2 >> n;

    int ans = INT_MIN; // 初始化為最小整數，確保任何合法收益都會被考慮

    for (int x1 = 0; x1 <= n; x1++) {
        int x2 = n - x1;
        int y1 = A1 * x1 * x1 + B1 * x1 + C1;
        int y2 = A2 * x2 * x2 + B2 * x2 + C2;
        ans = max(ans, y1 + y2);
    }

    cout << ans << endl;
    return 0;
}
