#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size()-1;
        vector<int> dp;
        if (n == 0)
        {
            return nums[0];
        }
        if (n == 1)
        {
            return max(nums[0], nums[1]);
        }
        for (int i = 2; i < n+1; i++)
        {
            dp[0] = nums[0];
            dp[1] = max(nums[0], nums[1]);
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }
        
        return dp[n];
    }
};