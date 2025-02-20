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
    //中序
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
                stk.pop();// 将该节点弹出，避免重复操作，下面再将右中左节点添加到栈中
                if (node->right)
                {
                    stk.push(node->right);// 添加右节点
                }

                stk.push(node);// 添加中节点
                stk.push(NULL);// 中节点访问过，但是还没有处理，加入空节点做为标记。

                if (node->left)
                {
                    stk.push(node->left);// 添加左节点
                }
            }
            else // 只有遇到空节点的时候，才将下一个节点放进结果集
            {
                stk.pop();  // 将空节点弹出
                node = stk.top();  // 重新取出栈中元素
                stk.pop();
                res.push_back(node->val);
            }
        }
        return res;
    }

};