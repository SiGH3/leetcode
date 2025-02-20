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
    // ��һ��map��¼���������е���ֵ�������ҵ������ĸ��ڵ㡣
    // ���ڵ���ʵ������������ĵ�һ��Ԫ�أ��Ӷ������ҵ������и��ڵ��λ��
    // ��һ������֪���������Ľڵ��������Ӷ�����֪������������������������������ı߽�
    // ���ǹ������ڵ㣬��������߽�ݹ�Ľ������������ӵ����ڵ���
    // ���ظ��ڵ㼴�ɡ�
    unordered_map<int, int>mp;
    TreeNode* rebuildtree(vector<int>& preorder, vector<int>& inorder, int preleft, int preright, int inleft, int inright) {
        // �ݹ�����
        if (preleft > preright) return nullptr;
        // ���ڵ���ʵ������������ĵ�һ��Ԫ�أ��Ӷ������ҵ������и��ڵ��λ��
        int preroot = preorder[preleft];
        int midroot = mp[preroot];
        // ��һ������֪���������Ľڵ��������Ӷ�����֪������������������������������ı߽�
        int left_tree = midroot - inleft;
        // ���ǹ������ڵ㣬��������߽�ݹ�Ľ������������ӵ����ڵ���
        TreeNode* root = new TreeNode(preroot);
        // ���ǹ������ڵ㣬��������߽�ݹ�Ľ������������ӵ����ڵ���
        // ������
        root->left = rebuildtree(preorder, inorder, preleft + 1, preleft + left_tree, inleft, midroot - 1);
        // ������   
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