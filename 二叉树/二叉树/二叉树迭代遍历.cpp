#include<iostream>
#include<vector>
#include<stack>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution
{
public:
    //ǰ����� ������
    //���ڵ���ջ�����ڵ��ջ���Һ�����ջ��������ջ�����ӳ�ջ���Һ��ӳ�ջ
    //ע��սڵ㲻��ջ
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root == NULL)
        {
            return res;
        }
        stk.push(root);  //���ڵ���ջ
        while (!stk.empty())
        {
            TreeNode* node = stk.top(); 
            stk.pop(); //�ڵ��ջ
            res.push_back(node->val);//����ֵ���浽������
            if (node->right)  //����Һ��Ӳ�Ϊ��
            {
                stk.push(node->right);  //�Һ�����ջ
            }
            if (node->left)  //������Ӳ�Ϊ��
            {
                stk.push(node->left);  //������ջ
            }
            return res;
        }
    }


    //������� ������
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur != NULL || !stk.empty())
        {
            if (cur != NULL)  //ָ����ʽڵ�ֱ����ײ�
            {
                stk.push(cur);  //�����ʵĽڵ����ջ
                cur = cur->left;  //ָ��ָ������
            }
            else
            {
                cur = stk.top(); //ָ��ָ��Ҫ��ջ��Ԫ��
                stk.pop(); //��ջ
                res.push_back(cur->val);  //����ֵ��������
                cur = cur->right;   //ָ��ָ���Һ���                            

            }
        }
        return res;
    }

    //������� ������
    //�������������˳��������->�����󣩣��ٷ�תres����
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root == NULL)
        {
            return res;
        }
        stk.push(root);  //���ڵ���ջ
        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop(); //�ڵ��ջ
            res.push_back(node->val);//����ֵ���浽������
            if (node->left)  //������Ӳ�Ϊ��
            {
                stk.push(node->left);  //������ջ
            }
            if (node->right)  //����Һ��Ӳ�Ϊ��
            {
                stk.push(node->right);  //�Һ�����ջ
            }
            reverse(res.begin(), res.end());
            return res;
        }
    }
};



