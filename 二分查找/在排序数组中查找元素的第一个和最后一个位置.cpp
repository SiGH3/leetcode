#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
//要找第一个小于和第一个大于target的位置,两个二分
    int findLeft(vector<int>& nums, int target){
        int n = nums.size();
        int left =0;
        int right = n-1;
        int res = -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]>=target){
                if(nums[mid]==target){
                    res = mid;
                }
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return res;
    }

    int findRight(vector<int>& nums, int target){
        int n = nums.size();
        int left =0;
        int right = n-1;
        int res = -1;
        while(left<=right){
            int mid = left+(right-left)/2;
            if(nums[mid]<=target){
                if(nums[mid]==target){
                    res = mid;
                }
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return res;
    }

    
    vector<int> searchRange(vector<int>& nums, int target) {  
        return {findLeft(nums,target),findRight(nums,target)};
    }
};