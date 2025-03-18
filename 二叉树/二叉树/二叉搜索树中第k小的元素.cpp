#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr) {}
    TreeNode(int x):val(x),left(nullptr),right(nullptr) {}
};

class Solution{
public:
    int count=0;
    TreeNode* res= nullptr;

    void traversal(TreeNode* root ,int k){
        if(root==nullptr){
            return;
        }
        if(root->left){
            traversal(root->left,k);
        }
        count++;
        if(count==k){
            res = root;
            return;
        }
        if(root->right){
            traversal(root->right,k);
        }
    }

    int kthSmallest(TreeNode* root, int k){
        traversal(root,k);
        return res->val;
    }
};

TreeNode* buildTree(const vector<string>& input){
    int n=input.size();
    if(n==0){
        return NULL;
    }
    TreeNode* root = new TreeNode(stoi(input[0]));
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;
    while(index<n){
        TreeNode* node = q.front();
        q.pop();

        if(input[index]!="null"){
            node->left =new TreeNode(stoi(input[index]));
            q.push(node->left);
        }
        index++;
        if(index<n&&input[index]!="null"){
            node->right = new TreeNode(stoi(input[index]));
            q.push(node->right);
        }
        index++;
    }
    return root;
}

int main(){
    vector<string> input = {"5","3","6","2","4","null","null","1"};
    int k = 3;
    TreeNode* root = buildTree(input);
    Solution sol;
    cout << sol.kthSmallest(root,k);
    return 0;
}