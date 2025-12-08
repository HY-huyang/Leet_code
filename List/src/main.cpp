
//02.01去除重复节点
int main() {
    vector<int>ve = { 1, 2, 3, 3, 2, 1 };
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().removeDuplicateNodes(ls);
    cout << res;
    return 0;
}

//61旋转链表
int main() {
    vector<int>ve = { 1,2 };
    int k = 2;
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().rotateRight(ls, k);
    cout << res;
    return 0;
}

int main() {
    vector<int>ve = { 1,1,1,2,3 };
    int k = 2;
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().deleteDuplicates(ls);
    cout << res;
    return 0;
}

