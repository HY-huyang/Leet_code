struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 单链表
ListNode* to_list(const vector<int>num) {
    int len = static_cast<int>(num.size());
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

// pos节点的循环链表
ListNode* to_list(const vector<int>& num, int pos) {
    int len = static_cast<int>(num.size());
    if (len == 0) return nullptr;
    ListNode* head = new ListNode(num[0]);
    ListNode* now = head;
    ListNode* cycle_node = nullptr;
    for (int i = 1; i < len; ++i) {
        ListNode* item = new ListNode(num[i]);
        now->next = item;
        now = item;
        if (i == pos) cycle_node = item;
    }
    if (pos != -1) now->next = cycle_node;
    return head;
}
