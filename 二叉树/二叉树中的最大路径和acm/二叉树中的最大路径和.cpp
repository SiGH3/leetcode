#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <climits>  // 包含 INT_MIN

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
}; 

class Solution {
public:
    int maxSum = INT_MIN;  // 初始化为最小整数，以便与其他路径和比较

    // 递归计算每个节点的最大单边路径和
    int traversal(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }

        // 递归计算左右子树的最大路径和
        int leftSum = max(traversal(root->left), 0);  // 如果左子树路径和是负数，不选
        int rightSum = max(traversal(root->right), 0);  // 如果右子树路径和是负数，不选

        // 计算当前节点的路径和：左子树 + 当前节点 + 右子树
        int curSum = leftSum + rightSum + root->val;

        // 更新全局最大路径和
        maxSum = max(maxSum, curSum);

        // 返回当前节点的最大单边路径和
        return max(leftSum, rightSum) + root->val;
    }

    // 返回最大路径和
    int maxPathSum(TreeNode* root) {
        traversal(root);
        return maxSum;
    }
};

// 辅助函数：根据输入数组构建二叉树
TreeNode* buildTree(const vector<string>& vals) {
    if (vals.empty()) return NULL;

    TreeNode* root = new TreeNode(stoi(vals[0]));  // 根节点
    queue<TreeNode*> q;
    q.push(root);

    int index = 1;
    while (index < vals.size()) {
        TreeNode* node = q.front();
        q.pop();

        if (vals[index] != "null") {
            node->left = new TreeNode(stoi(vals[index]));  // 左子节点
            q.push(node->left);
        }
        index++;

        if (index < vals.size() && vals[index] != "null") {
            node->right = new TreeNode(stoi(vals[index]));  // 右子节点
            q.push(node->right);
        }
        index++;
    }

    return root;
}


int main() {
    //vector<string> input = {"-10", "9", "20", "null", "null", "15", "7"};  

    //如果需要输入的话，先输入节点个数N（包括空节点）
    int N;
    cin>>N;
    vector<string> input(N);
    for (int i = 0; i < N; i++) {
        cin >> input[i];
    }

    Solution solution;

    // 构建二叉树
    TreeNode* treeRoot = buildTree(input);

    // 输出最大路径和
    cout << solution.maxPathSum(treeRoot) << endl;

    return 0;
}
