#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> left(n,1);
        vector<int> right(n,1);
        for(int i=1;i<n;i++){   //left[i]表示nums[i]左边数字的乘积
            left[i] = left[i-1]*nums[i-1];
        }
        for(int i=n-2;i>1;i--){  //right[i]表示nums[i]右边数字的乘积
            right[i] = right[i+1]*nums[i+1];
        }
        return res;
    }
};