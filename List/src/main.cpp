int main() {
    vector<int>ve = { 1, 2, 3, 3, 2, 1 };
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().removeDuplicateNodes(ls);
    cout << res;
    return 0;
}