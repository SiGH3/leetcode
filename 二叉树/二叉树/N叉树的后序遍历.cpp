#include<iostream>
#include<vector>
#include<queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
private:
    vector<int> res;
    void traversal(Node* root)
    {
        if (root == NULL)
        {
            return;
        }
        
        for (int i = 0; i < root->children.size(); i++)
        {
            traversal(root->children[i]);
        }
        res.push_back(root->val);
    }

public:
    vector<int> postorder(Node* root)
    {
        res.clear();
        traversal(root);
        return res;
    }
};