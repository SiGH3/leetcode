#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    // ������Ѱ�������к�Ϊ k ��������ĸ���
    int subarraySum(vector<int>& nums, int k) {
        // ��ϣ�� mp �����洢ǰ׺�ͳ��ֵĴ���
        unordered_map<int, int> mp;

        // ��ʼ����ϣ����ǰ׺��Ϊ0�Ĵ�����Ϊ1������������ĺ�Ϊ0��
        mp[0] = 1;

        // ����������¼�������������������
        int count = 0;

        // ǰ׺�ͱ����������洢��ͷ����ǰλ�õ��ۼӺ�
        int pre = 0;

        // �������� nums
        for (auto& x : nums) {
            // ����ǰ׺��
            pre += x;

            // �����ǰǰ׺�ͼ�ȥ k ��ֵ�ڹ�ϣ���г��ֹ�
            // ˵������һ�������飬��͵��� k
            if (mp.find(pre - k) != mp.end()) {
                // �ۼӷ������������������
                count += mp[pre - k];
            }

            // ����ǰ׺�ͳ��ֵĴ���
            mp[pre]++;
        }

        // �����������������������
        return count;
    }
};
