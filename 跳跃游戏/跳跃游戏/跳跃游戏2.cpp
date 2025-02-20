#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//每次在上一次能走到的范围里选择能走得最远的作为下一次的起跳点
class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }

        int point_num = 0;   //计数
        int cur_end = 0;    //最远边界的下标
        int farthest = 0;  //最远可到达的位置下标
        
        for (int i = 0; i < n-1; i++)  //遍历每个元素至倒数第二个
        {
            farthest = max(farthest, i + nums[i]); //更新最远可到达位置下标

            if (i == cur_end)   //如果i到达当前边界，计数，并更新边界到新的最远位置
            {
                point_num++;
                cur_end = farthest;
                
                if (cur_end >= n - 1)
                {
                    break;
                }

            }
          
        }

        return point_num;
    }
};


class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) 
        {
            if (maxPos >= i) 
            {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) 
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

