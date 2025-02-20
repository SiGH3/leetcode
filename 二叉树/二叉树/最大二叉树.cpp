#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        //�������������СΪ1��˵����������Ҷ�ӽڵ���
        if (nums.size() == 1)
        {
            node->val = nums[0];
            return node;
        }

        //1 �����ֵ
        int maxValue = 0;
        int maxValueIndex = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > maxValue)
            {
                maxValue = nums[i];
                maxValueIndex = i;
            }
        }
        node->val = maxValue;

        //2 ���ֵ��ߣ�����������
        if (maxValueIndex > 0)
        {
            vector<int> newVec(nums.begin(), nums.begin() + maxValueIndex);
            node->left = constructMaximumBinaryTree(newVec);
        }

        //3 ���ֵ�ұߣ�����������
        if (maxValueIndex < nums.size()-1)
        {
            vector<int> newVec(nums.begin() + maxValueIndex + 1, nums.end());
            node->right = constructMaximumBinaryTree(newVec);
        }
        return node;
    }
};