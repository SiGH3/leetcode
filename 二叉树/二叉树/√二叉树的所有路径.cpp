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
private:
    void traversal(TreeNode* cur, vector<int>& path, vector<string>& res)
    {
        path.push_back(cur->val);
        if (cur->left == NULL && cur->right == NULL)
        {
            string sPath;
            for (int i = 0; i < path.size()-1; i++)
            {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            res.push_back(sPath);
            return;
        }
        if (cur->left)
        {
            traversal(cur->left, path, res);
            path.pop_back();
        }
        if (cur->right)
        {
            traversal(cur->right, path, res);
            path.pop_back();
        }
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        vector<int> path;
        if (root == NULL)
            return res;
        traversal(root, path, res);
        return res;

    }
};


class solution {
private:
    void traversal(TreeNode* node, vector<int> &path, vector<string> &res)
    {
        path.push_back(node->val);
        if (node->left == NULL && node->right == NULL)
        {
            string sPath;
            for (int i = 0; i < path.size() - 1; i++) {
                sPath += to_string(path[i]);
                sPath += "->";
            }
            sPath += to_string(path[path.size() - 1]);
            res.push_back(sPath);
            return;
        }
        if (node->left)
        {
            traversal(node->left, path, res);
            path.pop_back();
        }
        if (node->right)
        {
            traversal(node->right, path, res);
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        if (root == NULL)
        {
            return result;
        }
        traversal(root,path,result);
        return result;
    
    }
};