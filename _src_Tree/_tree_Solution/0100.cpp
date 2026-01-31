class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == NULL && q == NULL)return true;
        if ((p == NULL && q != NULL) || p != NULL && q == NULL)return false;
        if (p->val != q->val)return false;
        queue<TreeNode*>que;
        queue<TreeNode*>ue;
        que.push(p), ue.push(q);
        while (!que.empty() && !ue.empty()) {
            TreeNode* root1 = que.front();
            que.pop();
            TreeNode* root2 = ue.front();
            ue.pop();
            if (root1->val != root2->val)return false;
            if ((root1->left && !root2->left) || (!root1->left && root2->left) || (!root1->right && root2->right) || (root1->right && !root2->right))
                return false;
            if (root1->left && root2->left)que.push(root1->left), ue.push(root2->left);
            if (root1->right && root2->right)que.push(root1->right), ue.push(root2->right);
        }
        return true;
    }
};

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p && q) {
            if (p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right)) {
                return true;
            }
            else
                return false;
        }
        if (p == q)
            return true;
        return false;
    }
};