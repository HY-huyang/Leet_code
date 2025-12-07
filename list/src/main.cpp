//面试题02.01.移除重复节点

int main() {      
    vector<int>ve = { 1, 2, 3, 3, 2, 1 };
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().removeDuplicateNodes(ls);
    cout << res;
    return 0;
}
