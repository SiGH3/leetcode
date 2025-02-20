#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


//最远可达是否大于最后一个下标

class Solution
{
public:
    bool canJump(vector<int>& nums)
    {
        int max_sum = 0;
        
        for (int i = 0; i < nums.size();i++)
        {
            if (i > max_sum)
            {
                return false;
            }
            max_sum = max(max_sum, i + nums[i]);
            
            if (max_sum >= nums.size() - 1)
            {
                return true;
            }
        }
       
       
        return false;
        
        
    }
};