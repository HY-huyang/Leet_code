class Solution {
public:
    vector<int> LNR(TreeNode* root, vector<int>& ans) {
        if (!root)return ans;
        LNR(root->left, ans);
        ans.push_back(root->val);
        LNR(root->right, ans);
        return ans;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>res;
        if (!root)return res;
        LNR(root, res);
        return res;
    }
};