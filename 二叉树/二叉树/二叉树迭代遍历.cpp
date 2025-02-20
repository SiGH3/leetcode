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
    //前序遍历 中左右
    //根节点入栈，根节点出栈，右孩子入栈，左孩子入栈，左孩子出栈，右孩子出栈
    //注意空节点不入栈
    vector<int> preorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root == NULL)
        {
            return res;
        }
        stk.push(root);  //根节点入栈
        while (!stk.empty())
        {
            TreeNode* node = stk.top(); 
            stk.pop(); //节点出栈
            res.push_back(node->val);//将数值保存到数组中
            if (node->right)  //如果右孩子不为空
            {
                stk.push(node->right);  //右孩子入栈
            }
            if (node->left)  //如果左孩子不为空
            {
                stk.push(node->left);  //左孩子入栈
            }
            return res;
        }
    }


    //中序遍历 左中右
    vector<int> inorderTraversal(TreeNode* root) 
    {
        vector<int> res;
        stack<TreeNode*> stk;
        TreeNode* cur = root;
        while (cur != NULL || !stk.empty())
        {
            if (cur != NULL)  //指针访问节点直到最底层
            {
                stk.push(cur);  //将访问的节点放入栈
                cur = cur->left;  //指针指向左孩子
            }
            else
            {
                cur = stk.top(); //指针指向要出栈的元素
                stk.pop(); //出栈
                res.push_back(cur->val);  //将数值存入数组
                cur = cur->right;   //指针指向右孩子                            

            }
        }
        return res;
    }

    //后序遍历 左右中
    //调整先序的左右顺序（中左右->中右左），再反转res数组
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> res;
        stack<TreeNode*> stk;
        if (root == NULL)
        {
            return res;
        }
        stk.push(root);  //根节点入栈
        while (!stk.empty())
        {
            TreeNode* node = stk.top();
            stk.pop(); //节点出栈
            res.push_back(node->val);//将数值保存到数组中
            if (node->left)  //如果左孩子不为空
            {
                stk.push(node->left);  //左孩子入栈
            }
            if (node->right)  //如果右孩子不为空
            {
                stk.push(node->right);  //右孩子入栈
            }
            reverse(res.begin(), res.end());
            return res;
        }
    }
};



