#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
            
        int n = nums.size();
        int l=0,r=n-1;
        while(l<r){
            int mid=l+(r-l)/2;
            //中间值小于右值，说明最小值还在左边，可以忽略右侧区间
            if(nums[mid]<nums[r]){
                r=mid;
            }
            //中间值大于等于右值，说明最小值在右侧区间，可以忽略左侧区间
            else{
                l = mid+1;
            }
        }
        return nums[l];
    }
};