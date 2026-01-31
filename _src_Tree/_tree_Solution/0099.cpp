class Solution {
    TreeNode* t1, * t2, * pre;
    void inorder(TreeNode* root) {
        if (root == NULL)return;
        inorder(root->left);
        if (pre != NULL && pre->val > root->val) {
            if (t1 == NULL)t1 = pre;
            t2 = root;
        }
        pre = root;
        inorder(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(t1->val, t2->val);
        return;
    }
};
m
        