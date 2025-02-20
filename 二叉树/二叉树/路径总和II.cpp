#include<iostream>
#include<vector>
#include<stack>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


//�����������飩
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        if (root == NULL) {
            return res;
        }
        stack<pair<TreeNode*, vector<int>>> stk;
        stk.push({ root, {root->val} });
        if (!root->left && !root->right && root->val == targetSum)
        {
            res.push_back({ root->val });
            return res;
        }
        while (!stk.empty())
        {
            pair<TreeNode*, vector<int>> node = stk.top();
            stk.pop();
            vector<int> cur=node.second;
            if (node.first->left == NULL && node.first->right == NULL && accumulate(cur.begin(), cur.end(), 0) == targetSum)
            {
                res.push_back(cur);
            }
            if (node.first->right)
            {
                vector<int> path = cur;
                path.push_back(node.first->right->val);
                stk.push({ node.first->right, path});

            }
            if (node.first->left)
            {
                vector<int> path = cur;
                path.push_back(node.first->left->val);
                stk.push({ node.first->left, path });
            }
            
        }
        return res;

    }
};

//�ݹ�
class solution {
private:
    vector<vector<int>> res;
    vector<int> path;
    //����������������Ҫ����ֵ
    void traversal(TreeNode* root, int count)
    {
        if (!root->left && !root->right && count == 0)//�����ӽڵ����ҵ��˺�Ϊsum��·��
        {
            res.push_back(path);
            return;
        }
        if (!root->left && !root->right)//�����ӽڵ㣬û���ҵ���Ϊsum��·��
        {
            return;
        }
        if (root->left)
        {
            path.push_back(root->left->val);
            count -= root->left->val;
            traversal(root->left, count); //�ݹ�
            count += root->left->val;  //����
            path.pop_back(); //����
        }
        if (root->right)
        {
            path.push_back(root->right->val);
            count -= root->right->val;
            traversal(root->right, count); 
            count += root->right->val;
            path.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        path.clear();
        if (root == NULL) return res;
        path.push_back(root->val); // �Ѹ��ڵ�Ž�·��
        traversal(root, sum - root->val);
        return res;
    }

};