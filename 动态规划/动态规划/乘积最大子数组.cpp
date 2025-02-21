#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
    int maxProduct(vector<int>& nums){
        int n = nums.size();
        int res = nums[0];
        vector<int> dpMin(n+1);
        dpMin[0]=nums[0];
        vector<int> dpMax(n+1);
        dpMax[0]=nums[0];
        for(int i = 1;i<nums.size();i++){
            dpMax[i]=max(dpMax[i-1]*nums[i],max(nums[i],dpMin[i-1]*nums[i]));
            dpMin[i]=min(dpMin[i-1]*nums[i],min(nums[i],dpMax[i-1]*nums[i]));   
            res = max(res,dpMax[i]);
        }
        return res;
    }
};