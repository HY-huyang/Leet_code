class Solution {
public:
    bool hasCycle(ListNode* head) {
        if (!head || !head->next)return false;
        int i = 0;
        ListNode* quick = head->next, * slow = head;
        while (quick->next && quick->next->next) {
            quick = quick->next->next;
            slow = slow->next;
            if (slow == quick || quick->next == slow || slow->next == quick)return true;
        }
        return false;
    }
};