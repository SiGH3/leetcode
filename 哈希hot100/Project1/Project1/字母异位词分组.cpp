#include<vector>
#include<iostream>
#include<string>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> mp;
        for (string& str: strs)
        {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());  //对字符串进行排序，将排序后的字符串作为键，异位字作为值，构造哈希表
            mp[sorted_str].emplace_back(str);
        }
        vector<vector<string>> res;  //将哈希表中的结果取出
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            res.emplace_back(it->second);
        }
        return res;
    }
};