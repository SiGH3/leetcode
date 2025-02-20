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
        //2������������һ�������ǵ�ǰ�ĸ��ڵ�
        int rootValue = postorder[postorder.size() - 1];
        TreeNode* root = new TreeNode(rootValue);

        //Ҷ�ӽڵ�
        if (postorder.size() == 1)
            return root;

        //3��ǰ����������и��
        int delimiterIndex;
        for(delimiterIndex=0;delimiterIndex<inorder.size();delimiterIndex++)
        {
            if (inorder[delimiterIndex] == rootValue)
            {
                break;
            }
        }

        //4 �и���������
        // 
        //����ҿ� [0, delimiterIndex)
        vector<int> leftInorder(inorder.begin(), inorder.begin() + delimiterIndex);
        //����ҿ� [delimiterIndex, end)
        vector<int> rightInorder(inorder.begin() + delimiterIndex+1,inorder.end());


        //5 �и��������
        //postorder ����ĩβԪ�أ���Ϊ���Ԫ�ؾ����м�ڵ㣬�Ѿ��ù���
        postorder.resize(postorder.size() - 1);
        //����ҿ���ʹ�������������С��Ϊ�и�㣺[0, leftInorder.size)
        vector<int> leftPostorder(postorder.begin(), postorder.begin() + leftInorder.size());
        // [leftInorder.size(), end)
        vector<int> rightPostorder(postorder.begin() + leftInorder.size(), postorder.end());


        //6 �ݹ�
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