#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n; // 讀入目標數字

    // dp[x][y]，x 為位數，y 為最高位數字
    vector<vector<long long>> dp(20, vector<long long>(10, 0));

    // 初始化 1 位數的階梯數字
    for (int i = 1; i <= 9; i++) dp[1][i] = 1;

    // 動態規劃填表
    for (int i = 2; i < 20; i++) { // 最多處理 19 位數
        for (int j = 1; j <= 9; j++) { // 最高位數
            for (int k = j; k <= 9; k++) { // 下一位數不能小於當前位
                dp[i][j] += dp[i - 1][k];
            }
        }
    }

    // 加上所有位數小於目標數字的階梯數字
    string s = to_string(n);
    int l = s.length();
    long long result = 0;

    for (int i = 1; i < l; i++) { // 累加所有位數小於目標數字的情況
        for (int j = 1; j <= 9; j++) {
            result += dp[i][j];
        }
    }

    // 處理與目標數字相同位數的部分
    int pre = 0;
    for (int i = 0; i < l; i++) {
        int cur = s[i] - '0'; // 當前數字
        for (int j = (i == 0 ? 1 : pre); j < cur; j++) {
            result += dp[l - i][j];
        }
        if (cur < pre) break; // 若不符合階梯數字條件，提前結束
        pre = cur; // 更新上一位數字
    }

    // 最後檢查是否包含目標數字本身
    bool is_step_number = true;
    for (int i = 1; i < l; i++) {
        if (s[i] < s[i - 1]) {
            is_step_number = false;
            break;
        }
    }
    if (is_step_number) result++;

    cout << result << endl;
    return 0;
}
