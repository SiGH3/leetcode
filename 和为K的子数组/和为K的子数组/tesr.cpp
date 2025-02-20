#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // 函数：寻找数组中和为 k 的子数组的个数
    int subarraySum(vector<int>& nums, int k) {
        // 哈希表 mp 用来存储前缀和出现的次数
        unordered_map<int, int> mp;

        // 初始化哈希表，将前缀和为0的次数设为1（即空子数组的和为0）
        mp[0] = 1;

        // 计数器，记录满足条件的子数组个数
        int count = 0;

        // 前缀和变量，用来存储从头到当前位置的累加和
        int pre = 0;

        // 遍历数组 nums
        for (auto& x : nums) {
            // 更新前缀和
            pre += x;

            // 如果当前前缀和减去 k 的值在哈希表中出现过
            // 说明存在一个子数组，其和等于 k
            if (mp.find(pre - k) != mp.end()) {
                // 累加符合条件的子数组个数
                count += mp[pre - k];
            }

            // 更新前缀和出现的次数
            mp[pre]++;
        }

        // 返回满足条件的子数组个数
        return count;
    }
};
