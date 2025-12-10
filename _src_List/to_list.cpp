struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* to_list(const vector<int>num) {
    int len = num.size();
    if (len == 0)return NULL;
    ListNode* head = new ListNode(num[0]);
    ListNode* now = head;
    for (int i = 1; i < len; ++i) {
        ListNode* item = new ListNode(num[i]);
        now->next = item;
        now = item;
    }
    return head;
}