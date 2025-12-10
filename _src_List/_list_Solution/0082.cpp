class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* fhead = new ListNode(101, head);
        ListNode* itm = head;
        ListNode* fas = fhead;
        while (itm && itm->next) {
            if (itm->val == itm->next->val) {
                int tmp = itm->val;
                while (itm && itm->val == tmp) {
                    itm = itm->next;
                }
                fas->next = itm;
            }
            else {
                itm = itm->next;
                fas = fas->next;
            }

        }
        return fhead->next;
    }
};