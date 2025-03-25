#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// 层次遍历函数
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result; // 存储最终结果
    if (!root) return result;  // 如果根节点为空，直接返回空结果

    queue<TreeNode*> q; // 使用队列进行BFS
    q.push(root);       // 将根节点加入队列

    while (!q.empty()) {
        int levelSize = q.size(); // 当前层的节点数量
        vector<int> currentLevel; // 存储当前层的节点值

        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front(); // 取出队首节点
            q.pop();
            currentLevel.push_back(node->val); // 将节点值加入当前层

            // 将左右子节点加入队列
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(currentLevel); // 将当前层加入结果
    }

    return result;
}