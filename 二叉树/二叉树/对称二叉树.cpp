#include<iostream>
#include<vector>
#include<queue>

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
    bool compare(TreeNode* left, TreeNode* right)
    {
        if (left == NULL && right != NULL)  //��� �Ҳ���
        {
            return false;
        }
        else if (left != NULL && right == NULL)  //�󲻿� �ҿ�
        {
            return false;
        }
        else if (left == NULL && right == NULL)  //���Ҷ���
        {
            return true;
        }
        else if (left->val != right->val)  //���Ҷ����գ�������ֵ!=��ֵ
        {
            return false;
        }

        //���Ҳ��գ�������ֵ���
        //�ж���һ��
        bool outside = compare(left->left, right->right);
        bool inside = compare(left->right, right->left);
        bool isSame = outside && inside;
        return isSame;
    }



    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
        {
            return true;
        }
        return compare(root->left, root->right);
    }
};