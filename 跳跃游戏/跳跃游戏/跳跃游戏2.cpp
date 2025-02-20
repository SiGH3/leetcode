#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//ÿ������һ�����ߵ��ķ�Χ��ѡ�����ߵ���Զ����Ϊ��һ�ε�������
class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }

        int point_num = 0;   //����
        int cur_end = 0;    //��Զ�߽���±�
        int farthest = 0;  //��Զ�ɵ����λ���±�
        
        for (int i = 0; i < n-1; i++)  //����ÿ��Ԫ���������ڶ���
        {
            farthest = max(farthest, i + nums[i]); //������Զ�ɵ���λ���±�

            if (i == cur_end)   //���i���ﵱǰ�߽磬�����������±߽絽�µ���Զλ��
            {
                point_num++;
                cur_end = farthest;
                
                if (cur_end >= n - 1)
                {
                    break;
                }

            }
          
        }

        return point_num;
    }
};


class Solution 
{
public:
    int jump(vector<int>& nums) 
    {
        int maxPos = 0, n = nums.size(), end = 0, step = 0;
        for (int i = 0; i < n - 1; ++i) 
        {
            if (maxPos >= i) 
            {
                maxPos = max(maxPos, i + nums[i]);
                if (i == end) 
                {
                    end = maxPos;
                    ++step;
                }
            }
        }
        return step;
    }
};

