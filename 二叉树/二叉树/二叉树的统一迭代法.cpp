#include<iostream>
#include<vector>
#include<stack>

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
    //����
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root != NULL)
        {
            stk.push(root);
        }
        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            if (node != NULL)
            {
                stk.pop();// ���ýڵ㵯���������ظ������������ٽ�������ڵ���ӵ�ջ��
                if (node->right)
                {
                    stk.push(node->right);// ����ҽڵ�
                }

                stk.push(node);// ����нڵ�
                stk.push(NULL);// �нڵ���ʹ������ǻ�û�д�������սڵ���Ϊ��ǡ�

                if (node->left)
                {
                    stk.push(node->left);// �����ڵ�
                }
            }
            else // ֻ�������սڵ��ʱ�򣬲Ž���һ���ڵ�Ž������
            {
                stk.pop();  // ���սڵ㵯��
                node = stk.top();  // ����ȡ��ջ��Ԫ��
                stk.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }

};