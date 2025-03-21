#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
    int search(vector<int>& nums,int target){
        int n = nums.size();
        int l=0,r=n-1;
        if(n==0){
            return -1;
        }
        while(l<=r){
            int mid=l+ (r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[0]<=nums[mid]){  //判断左边数组是否有序
                if(nums[0] <= target && target < nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
            else{
                if(nums[mid] < target && target<=nums[n-1]){
                    l = mid+1;
                }
                else{
                    r = mid-1;
                }
            } 
        }
        return -1;
    }
};