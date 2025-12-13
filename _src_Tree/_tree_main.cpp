// 94_1  递归  _2  stack
int main() {
    vector<int>ve = { 1,2,3,4,5 };
    ListNode* ls = to_list(ve);
    Solution().reorderList(ls);
    return 0;
}

// 0102 二叉树的层序遍历
int main() {
    vector<optional<int>>vec = { 3,9,20,nullopt,nullopt,15,7 };
    TreeNode* tree = to_tree(vec);
    vector<vector<int>>num = Solution().levelOrder(tree);
    cout << num;
    return 0;
}

// 0112 路径总和
int main() {
    vector<optional<int>>vec = { 5,4,8,11,nullopt,13,4,7,2,nullopt,nullopt,nullopt,1 };
    int k = 22;
    TreeNode* tree = to_tree(vec);
    Solution().hasPathSum(tree, k);
    return 0;
}