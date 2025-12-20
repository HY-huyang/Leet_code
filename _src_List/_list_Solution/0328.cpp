// 1 在原链表上进行节点移动
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

// 2 创建两个新节点，ListNode* odd_node,后面跟head的奇数节点
                    ListNode* even_node，后面跟head的偶数节点
最后将两个新链表合并
