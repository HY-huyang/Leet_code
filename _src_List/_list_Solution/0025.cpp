class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* fhead = new ListNode(0, head);
        ListNode* itm = head;
        int head_size = 1;
        while (itm && itm->next) {
            head_size++;
            itm = itm->next;
        }
        itm = fhead;
        int ecops = head_size / k;      
        while (ecops--) {            //翻转链表的次数
            int i = k - 1;
            while (i--) {  
                //翻转链表
                ListNode* tmp = head->next;
                head->next = tmp->next;
                tmp->next = itm->next;
                itm->next = tmp;
            }
            itm = head;
            head = head->next;
        }
        return fhead->next;
    }
};