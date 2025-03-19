#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>

using namespace std;

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums,int k){

        vector<int> res;
        unordered_map<int,int> mp;
        for(auto num:nums){
            mp[num]++;
        }

        // 小顶堆，堆中存储 {频率, 数字}，按频率排序
        priority_queue<pair<int ,int>,vector<pair<int,int>>,greater<>> minHeap;

        for(const auto& [num,freq]:mp){
            minHeap.emplace(freq,num);
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        while(!minHeap.empty()){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};