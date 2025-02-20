#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    int coinChange(vector<int>& coins, int amount) 
    {
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        if (amount > 0)
        {
           
            for (int i = 1; i < amount+1; i++)
            {

                for (int j = 0; j < (int)coins.size(); j++)
                {
                    if (i - coins[j] >= 0)
                    {
                        dp[i] = min(dp[i],dp[i - coins[j]]+1);
                    }
                   
                }

            }
            return dp[amount] > amount ? -1 : dp[amount];
        }

        else
            return 0;
        
    }
};