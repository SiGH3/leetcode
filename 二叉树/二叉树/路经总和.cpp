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

//µÝ¹é
class Solution {
public:
    bool traversal(TreeNode* root, int targetSum)
    {
        if (!root->left && !root->right && targetSum==0)
        {
            return true;
        }
        if (!root->left && !root->right)
        {
            return false;
        }
        if (root->left)
        {
            if (traversal(root->left, targetSum - root->left->val))
            {
                return true;
            }
        }
        if (root->right)
        {
            if (traversal(root->right, targetSum - root->right->val))
            {
                return true;
            }
        }
        return false;

    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
        {
            return false;
        }
        return traversal(root, targetSum- root->val);
    }
};

//µü´ú
class solution
{
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (root == NULL)
        {
            return false;
        }
        stack<pair<TreeNode*, int>> st;
        st.push(pair<TreeNode*, int>(root, root->val));
        while (!st.empty())
        {
            pair<TreeNode*, int > node = st.top();
            st.pop();
            if (!node.first->left && !node.first->right && node.second == sum)
            {
                return true;
            }
            
            if (node.first->right)
            {
                st.push(pair<TreeNode*, int>(node.first->right, node.second+ node.first->right->val));
            }
            if (node.first->left)
            {
                st.push(pair<TreeNode*, int>(node.first->left, node.second + node.first->left->val));
            }
            
        }
        return false;
    }
};