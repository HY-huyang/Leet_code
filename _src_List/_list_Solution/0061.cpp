class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == NULL) return head;
        int n = 1;
        ListNode* itm = head;
        while (itm->next) {
            itm = itm->next;
            n++;
        }
        int add = n - k % n;
        if (add == n)return head;
        itm->next = head;
        while (add--) itm = itm->next;
        head = itm->next;
        itm->next = NULL;
        return head;
    }
};