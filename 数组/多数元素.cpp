#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int n = nums.size();
            int res;
            unordered_map<int,int> mp;
            for(auto num:nums){
                mp[num]++;
                if(mp[num]>n/2){
                    res = num;
                }
            }
            return res;
        }
    };

int main(){
    Solution sol;
    vector<int> nums = {2,2,1,1,1,2,2};
    int res = sol.majorityElement(nums);
    cout<< res;
    return 0;
}
