#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution{
public:
    int minSubArrayLen(int target, vector<int>& nums){
        int n = nums.size();
        if(n==0){
            return 0;
        }
        int res=INT_MAX;
        int start=0,end=0;
        int sum=0;
        while(end<n){
            sum+=nums[end];
            while(sum>=target){
                res = min(res,end-start+1);
                sum -=nums[start];
                start++;
            }
            end++;
        }
        return res==INT_MAX?0:res;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5};
    int target = 11;
    cout << sol.minSubArrayLen(target,nums);
}