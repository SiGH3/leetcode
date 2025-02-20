#include<iostream>
#include<vector>
#include<string>

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
    bool compare(TreeNode* p, TreeNode* q) {
        if (p == NULL && q != NULL)
        {
            return false;
        }
        else if (p != NULL && q == NULL)
        {
            return false;
        }
        else if (p == NULL && q == NULL)
        {
            return true;
        }
        else if(p->val != q->val)
        {
            return false;
        }
        else
        {
            bool left = compare(p->left, q->left);
            bool right = compare(p->right, q->right);
            bool isSame = left && right;
            return isSame;
        }

    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return compare(p, q);
    }
};
