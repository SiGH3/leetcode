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
private:
    TreeNode* traversal(vector<int>& inorder, vector<int>& postorder) {
        //1
        if (postorder.size() == 0)
            return NULL;
        //2后序遍历的最后一个数就是当前的根节点
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        //叶子节点
        if (postorder.size() == 1)
            return root;

        //3从前序遍历中找切割点
        int delimiterIndex;
        for(delimiterIndex=0;delimiterIndex<inorder.size();delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue)
            {
                break;
            }
        }

        //4 切割中序数组
        // 
        //左闭右开 [0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        //左闭右开 [delimiterIndex, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex+1,inorder.end());


        //5 切割后序数组
        //postorder 舍弃末尾元素，因为这个元素就是中间节点，已经用过了
        postorder.resize(postorder.size() - 1);
        //左闭右开，使用左中序数组大小作为切割点：[0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());


        //6 递归
        root->left = traversal(leftInorder, leftPostorder);
        root->right = traversal(rightInorder, rightPostorder);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        if (inorder.size() == 0 || postorder.size() == 0)
            return NULL;
        return traversal(inorder, postorder);
    }

};