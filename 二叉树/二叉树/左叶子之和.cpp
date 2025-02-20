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
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        if (root == NULL)
        {
            return 0;
        }
        int leftSubTreeVal = sumOfLeftLeaves(root->left);
        if (root->left != NULL && root->left->left == NULL && root->left->right == NULL)
        {
            leftSubTreeVal += root->left->val;
        }
        int rightSubTreeVal = sumOfLeftLeaves(root->right);

        sum = leftSubTreeVal + rightSubTreeVal;

        return sum;
    }
};