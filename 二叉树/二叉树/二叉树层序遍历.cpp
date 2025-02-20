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
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        queue<TreeNode*> que;
        if (root != NULL)
        {
            que.push(root);
        }
        vector<vector<int>> res;
        while (!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            while(size)
            {
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
                size--;
            }
            res.push_back(vec);
        }
        return res;
    }
};