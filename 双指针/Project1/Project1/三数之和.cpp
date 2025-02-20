#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;


class Solution 
{
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
        {
            int left = i + 1;
            int right = nums.size()-1;
            if (i > 0 && nums[i] == nums[i - 1])  //��fistȥ��
            {
                continue;
            }
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] > 0)
                {
                    right--;
                }
                else if (nums[i] + nums[left] + nums[right] < 0)
                {
                    left++;
                }
                else
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});

                    //��secondȥ��
                    while (left < right && nums[left] == nums[left+1])
                    {
                        left++;
                    }

                    //��thirdȥ��
                    while (left < right && nums[right] == nums[right-1])
                    {
                        right--;
                    }

                    left++;
                    right--;
                }
                                
            }

        }
        return res;
    }
};