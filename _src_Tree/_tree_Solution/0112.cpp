//_DFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)return false;
        if (targetSum - root->val == 0 && !root->left && !root->right)return true;
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};

//_BFS
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        queue<pair<TreeNode*, int>>que;
        if (root == NULL)return false;
        que.push({ root, targetSum - root->val });
        while (!que.empty()) {
            auto tmp = que.front();
            que.pop();
            TreeNode* node = tmp.first;
            int currentsum = tmp.second;
            if (currentsum == 0 && !node->left && !node->right)return true;
            if (node->left)que.push({ node->left, currentsum - node->left->val });
            if (node->right)que.push({ node->right, currentsum - node->right->val });
        }
        return false;
    }
};

//_stack
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        stack<pair<TreeNode*, int>>st;
        if (root == NULL)return false;
        st.push({ root,root->val });
        while (!st.empty()) {
            auto tmp = st.top();
            st.pop();
            TreeNode* node = tmp.first;
            int totalsum = tmp.second;
            if (!node->left && !node->right && totalsum == targetSum)return true;
            if (node->left)st.push({ node->left,totalsum + node->left->val });
            if (node->right)st.push({ node->right,totalsum + node->right->val });
        }
        return false;
    }
};