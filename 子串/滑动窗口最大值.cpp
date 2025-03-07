#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class Solution {
    public:
       //单调队列
        vector<int> maxSlidingWindow(vector<int>& nums, int k) {
            vector<int> res;
            deque<int> dq;  //存储索引，保持单调递减（队头最大）
            
            for(int i = 0; i<nums.size(); i++){
                //移除窗口外的元素
                if(!dq.empty() && dq.front() < i-k+1){
                    dq.pop_front();
                }
                //维护单调递减
                while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                    dq.pop_back();
                }
                //插入当前索引
                dq.push_back(i);
                //记录最大值
                if(i>=k-1){
                    res.push_back(nums[dq.front()]);
                }
            }
            return res;
        }
    };

// int main(){
//     Solution solution;
//     vector<int> input = {1,3,-1,-3,5,3,6,7};
//     int k = 3;
//     vector<int> output = solution.maxSlidingWindow(input,k);
//     for(int i=0;i<output.size();i++){
//         cout << output[i] << " ";
//     }
//     return 0;
// }