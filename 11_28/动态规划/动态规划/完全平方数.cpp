#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> dp(n + 1);  //dp[i]表示整数i最少可由多少个完全平方数表示
        for (int i = 1; i <= n; i++)
        {
            int m = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                m = min(m, dp[i - j * j]);
            }
            dp[i] = m + 1;
        }
        return dp[n];

    }
};