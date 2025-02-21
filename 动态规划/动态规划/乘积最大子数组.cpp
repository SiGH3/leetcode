#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProduct(vector<int>& nums){
        int n = nums.size();
        int res
        vector<int> dpMin(n+1);
        dpMin[0]=nums[0];
        vector<int> dpMax(n+1);
        dpMax[0]=nums[0];
        for(int i = 1;i<nums.size();i++){
           
            dpMin[i]=max(nums[i],dp[i-1]*nums[i]);   
        }

    }

}