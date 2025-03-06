#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

//原地哈希
class Solution1 {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Step 1: 将所有非正数和大于n的数替换为 n+1
        for (int i = 0; i < n; i++) {
            if (nums[i] <= 0 || nums[i] > n) {
                nums[i] = n + 1;
            }
        }

        // Step 2: 利用索引作为哈希表的存储方式
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            if (num >= 1 && num <= n) {
                nums[num - 1] = -abs(nums[num - 1]); // 标记出现的数字
            }
        }

        // Step 3: 找到第一个缺失的正整数
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1; // 缺失的最小正整数
            }
        }

        // 如果所有位置都正确，那么缺失的数字是 n + 1
        return n + 1;
    }
};


class Solution{
public:
    int firstMissingPositive(vector<int>& nums){
        unordered_set<int> set;
        int n = nums.size();
        for(auto num : nums){
            set.insert(num);
        }
        for(int i =1;i<=n;i++){
            if(set.find(i) == set.end()){
                return i;
            }
        }

        return n+1;
    }

};

int main(){
    Solution solution;
    vector<int> input = {10000,3,998,2,12345,1};
    int res= solution.firstMissingPositive(input);
    cout << res;
}