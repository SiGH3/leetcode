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

class Solution 
{
public:
    //递归法
    int getDepth(TreeNode* node)
    {
        if (node == NULL) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);

        if (node->left == NULL && node->right != NULL)
        {
            return 1 + rightDepth;
        }
        if (node->left != NULL && node->right == NULL)
        {
            return 1 + leftDepth;
        }
        int result = 1 + min(leftDepth, rightDepth);
        return result;
    }
    
    //迭代法，层序遍历
    int minDepth(TreeNode* root) 
    {
        queue<TreeNode*> que;
        int depth = 0;
        if (root != NULL)
        {
            que.push(root);
        }
        while (!que.empty())
        {
            int size = que.size();
            depth++;
            for (int i = 0; i < size; i++)
            {
                TreeNode* node = que.front();
                que.pop();
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
                if (node->left == NULL && node->right == NULL)
                {
                    return depth;
                }
            }
        }
        return depth;
    }
   

   
};