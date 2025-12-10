struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

TreeNode* to_tree(const vector<optional<int>>& v) {
    int n = v.size();
    if (n == 0) {
        return nullptr;
    }
    TreeNode* root = new TreeNode(v[0].value());
    deque<TreeNode*> dq = { root };
    int i = 1;
    while (!dq.empty()) {
        TreeNode* parent = dq.front();
        dq.pop_front();
        if (i >= n) {
            break;
        }
        const optional<int>& lc_x = v[i++];
        if (lc_x.has_value()) {
            TreeNode* lc = new TreeNode(lc_x.value());
            dq.push_back(lc);
            parent->left = lc;
        }
        if (i >= n) {
            break;
        }
        const optional<int>& rc_x = v[i++];
        if (rc_x.has_value()) {
            TreeNode* rc = new TreeNode(rc_x.value());
            dq.push_back(rc);
            parent->right = rc;
        }
    }
    return root;
}