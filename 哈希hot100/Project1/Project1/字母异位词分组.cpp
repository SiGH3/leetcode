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
            sort(sorted_str.begin(), sorted_str.end());  //���ַ����������򣬽��������ַ�����Ϊ������λ����Ϊֵ�������ϣ��
            mp[sorted_str].emplace_back(str);
        }
        vector<vector<string>> res;  //����ϣ���еĽ��ȡ��
        for (auto it = mp.begin(); it != mp.end(); it++)
        {
            res.emplace_back(it->second);
        }
        return res;
    }
};