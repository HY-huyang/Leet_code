class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode* fhead = new ListNode(0, head);
        ListNode* las = head;
        int i = 0;
        while (las) {
            if (i % 2 == 1 && las->next) {
                ListNode* itm = head->next;
                head->next = las->next;
                las->next = las->next->next;
                head->next->next = itm;
                head = head->next;

            }
            else {
                las = las->next;
            }
            i++;
        }
        return fhead->next;
    }
};