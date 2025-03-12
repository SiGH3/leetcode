#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){}
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
    TreeNode(int x, TreeNode* left, TreeNode* right):val(0),left(left),right(right){}
};

class Solution{
public:
    int widthOfBinaryTree(TreeNode* root){
        if(!root) return 0;

        queue<pair<TreeNode*,unsigned long long>> q;
        q.push({root,0});
        int maxWidth = 0;

        while(!q.empty()){
            int size = q.size();
            unsigned long long leftMost = q.front().second;
            unsigned long long rightMost = q.back().second;
            maxWidth = max(maxWidth,(int)(rightMost-leftMost+1));

            for(int i=0;i<size;i++){
                auto [node,index] = q.front();
                q.pop();

                index -= leftMost;

                if(node->left) q.push({node->left,index*2});
                if(node->right) q.push({node->right,index*2+1});
            }
        }
        return maxWidth;
    }
};

TreeNode* buildTree(const vector<string>& nums){
    if(nums.empty()) return nullptr;

    TreeNode* root = new TreeNode(stoi(nums[0]));
    queue<TreeNode*> q;
    q.push(root);

    int index = 1;
    while(index<nums.size()){
        TreeNode* node = q.front();
        q.pop();

        if (nums[index] != "null") {
            node->left = new TreeNode(stoi(nums[index]));  // 左子节点
            q.push(node->left);
        }
        index++;

        if (nums[index] != "null" && index<nums.size()) {
            node->right = new TreeNode(stoi(nums[index]));  // 左子节点
            q.push(node->right);
        }
        index++;
    }
    return root;
}

int main(){
    Solution sol;
    vector<string> nums = {"1","3","2","5","3","null","9"};
    TreeNode* root = buildTree(nums);
    cout << sol.widthOfBinaryTree(root) << endl;
    return 0;
}