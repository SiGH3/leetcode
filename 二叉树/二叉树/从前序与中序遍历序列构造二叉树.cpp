#include<iostream>
#include<vector>
#include<unordered_map>

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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);

        if (preorder.size() == 1)
            return root;

        int delimiterIndex;
        for (delimiterIndex = 0; delimiterIndex < inorder.size(); delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootVal)
                break;
        }

        vector<int> leftIn(inorder.begin(), inorder.begin() + delimiterIndex);
        vector<int> rightIn(inorder.begin() + delimiterIndex+1, inorder.end());

        vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftIn.size());
        vector<int> rightPre(preorder.begin() + 1 + leftIn.size(),preorder.end());

        root->left = traversal(leftPre, leftIn);
        root->right = traversal(rightPre, rightIn);

        return root;
            
    }


public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0)
        {
            return NULL;
        }
        return traversal(preorder, inorder);
    }
};



class solution {
public:
    // 用一个map记录中序数组中的数值，方便找到后续的根节点。
    // 根节点其实就是先序数组的第一个元素，从而可以找到中序中根节点的位置
    // 进一步可以知道左子树的节点数量，从而可以知道在先序和中序中左子树和右子树的边界
    // 我们构建根节点，根据这个边界递归的将左右子树连接到根节点上
    // 返回根节点即可。
    unordered_map<int, int>mp;
    TreeNode* rebuildtree(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright) {
        // 递归条件
        if (preleft > preright) return nullptr;
        // 根节点其实就是先序数组的第一个元素，从而可以找到中序中根节点的位置
        int preroot = preorder[preleft];
        int midroot = mp[preroot];
        // 进一步可以知道左子树的节点数量，从而可以知道在先序和中序中左子树和右子树的边界
        int left_tree = midroot - inleft;
        // 我们构建根节点，根据这个边界递归的将左右子树连接到根节点上
        TreeNode* root = new TreeNode(preroot);
        // 我们构建根节点，根据这个边界递归的将左右子树连接到根节点上
        // 左子树
        root->left = rebuildtree(preorder, inorder, preleft + 1, preleft + left_tree, inleft, midroot - 1);
        // 右子树   
        root->right = rebuildtree(preorder, inorder, preleft + 1 + left_tree, preright, midroot + 1, inright);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            mp[inorder[i]] = i;
        }
        return rebuildtree(preorder, inorder, 0, n - 1, 0, n - 1);
    }

};