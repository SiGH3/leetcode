#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // dp[i] 表示当前的余数是 i 的数的种类数
    vector<int> dp(3, 0);
    dp[0] = 1;  // 初始状态：空字符串的和对3取余为0

    for (int i = 0; i < n; i++) {
        if (s[i] == '?') {
            vector<int> new_dp(3, 0);
            // 对于每一个可能的数字0到9
            for (int digit = 0; digit < 10; digit++) {
                // 更新每一个余数的计数
                if (i == 0 && digit == 0) continue;
                for (int j = 0; j < 3; j++) {
                    new_dp[(j + digit) % 3] = (new_dp[(j + digit) % 3] + dp[j]) % MOD;
                }
            }
            dp = new_dp;
        } else {
            int digit = s[i] - '0';
            vector<int> new_dp(3, 0);
            // 更新余数
            for (int j = 0; j < 3; j++) {
                new_dp[(j + digit) % 3] = dp[j];
            }
            dp = new_dp;
        }
    }

    // 输出满足3的倍数的数的种类数
    cout << dp[0] << endl;

    return 0;
}
