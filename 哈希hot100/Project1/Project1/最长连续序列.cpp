#include<vector>
#include<iostream>
#include<string>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution 
{
public:
    int longestConsecutive(vector<int>& nums)
    {
        unordered_set<int> num_set;
        for (auto &num : nums)
        {
            num_set.insert(num);
        }
        
        int max_streak = 0;

        for (auto &num : num_set)
        {
            //num_set.count() �� unordered_set �����е�һ����Ա����
            //���ڼ��ָ����Ԫ���Ƿ�����ڼ�����
            //�����ص���һ����������ʾ��Ԫ���ڼ����г��ֵĴ���
                 
            if (!num_set.count(num - 1))  
            {
                int cur_num = num;
                int cur_streak = 1;

                while (num_set.count(cur_num + 1))
                {
                    cur_num += 1;
                    cur_streak += 1;
                }

                max_streak = max(max_streak, cur_streak);
            }
        }
        return max_streak;
    }
};