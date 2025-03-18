#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int limit = 1 << k;  // 2^k，元素的取值范围
    vector<vector<long long>> dp(n + 1, vector<long long>(limit, 0));
    
    // 初始状态，空数组时与和为0，异或和也为0
    dp[0][0] = 1;

    // 动态规划状态转移
    for (int i = 1; i <= n; ++i) {
        for (int x = 0; x < limit; ++x) {
            for (int val = 0; val < limit; ++val) {
                // 计算异或和与与和的条件
                if ((x ^ val) <= (x & val)) {
                    dp[i][x ^ val] = (dp[i][x ^ val] + dp[i - 1][x]) % MOD;
                }
            }
        }
    }

    // 计算最终答案
    long long result = 0;
    for (int x = 0; x < limit; ++x) {
        result = (result + dp[n][x]) % MOD;
    }

    cout << result << endl;

    return 0;
}
