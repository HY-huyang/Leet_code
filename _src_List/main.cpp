//02.01去除重复节点
int main() {
    vector<int>ve = { 1, 2, 3, 3, 2, 1 };
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().removeDuplicateNodes(ls);
    cout << res;
    return 0;
}

//0061 旋转链表
int main() {
    vector<int>ve = { 1,2 };
    int k = 2;
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().rotateRight(ls, k);
    cout << res;
    return 0;
}

//0082 删除排序链表中的重复元素
int main() {
    vector<int>ve = { 1,1,1,2,3 };
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().deleteDuplicates(ls);
    cout << res;
    return 0;
}

//0086 分隔链表
int main() {
    vector<int>ve = { 1,4,3,0,2,5,2 };
    int k = 3;
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().partition(ls, k);
    cout << res;
    return 0;
}

//0143 重排链表
int main() {
    vector<int>ve = { 1,2,3,4,5 };
    ListNode* ls = to_list(ve);
    Solution().reorderList(ls);
    return 0;
}

//0025 k个一组翻转链表
int main() {
    vector<int>ve = { 1,2,3,4,5 };
    int k = 2;
    ListNode* ls = to_list(ve);
    ListNode* res = Solution().reverseKGroup(ls, k);
    cout << res;
    return 0;
}