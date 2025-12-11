class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        queue<TreeNode*>qe;
        if (root)qe.push(root);
        while (!qe.empty()) {
            int qe_len = qe.size();         //记录这一层的节点数
            vector<int>vec;
            for (int i = 0; i < qe_len; i++) {
                TreeNode* node = qe.front();
                qe.pop();
                vec.push_back(node->val);
                if (node->left)qe.push(node->left);
                if (node->right)qe.push(node->right);
            }
            res.push_back(vec);
        }
        return res;
    }
};