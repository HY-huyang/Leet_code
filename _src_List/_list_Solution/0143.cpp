class Solution {
    ListNode* reverse(ListNode* las) {
        ListNode* node = new ListNode(0, las);
        while (las->next) {
            ListNode* itm = las->next;
            las->next = itm->next;
            itm->next = node->next;
            node->next = itm;
        }
        return node->next;
    }
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)return;
        ListNode* las = head, * mid = head;
        while (las->next && las->next->next) {
            las = las->next->next;
            mid = mid->next;
        }
        las = mid->next;
        mid->next = NULL;
        las = reverse(las);
        ListNode* fri = head;
        while (las) {
            ListNode* itm = las->next;
            las->next = fri->next;
            fri->next = las;
            fri = las->next;
            las = itm;
        }
    }
};