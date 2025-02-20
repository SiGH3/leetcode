#include<iostream>
#include<vector>

using namespace std;

class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        int sum = 0;
        int currentMax = nums[0];
        
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
                
            if (sum > currentMax)
            {
                currentMax = sum;
            }
            //else if (sum < 0)
            if (sum < 0)
            {
                sum = 0;
            }
                
        }
        return currentMax;
        
    }
};


int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution solution;
    cout << solution.maxSubArray(nums) << endl;
    return 0;
}