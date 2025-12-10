//86_1，构建两个新链表
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* minlis = new ListNode(0);
        ListNode* maxlis = new ListNode(0);
        ListNode* mi = minlis, * ma = maxlis;
        while (head) {
            if (head->val < x) {
                mi->next = head;
                mi = mi->next；
            }
            else {
                ma->next = head;
                ma = ma->next;
            }
            if (head->next == NULL)break;
            head = head->next;
        }
        ma->next = NULL;
        mi->next = maxlis->next;
        return minlis->next;
    }
};
//86_2在原链表上移动节点
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        if (!head || !head->next)return head;
        ListNode* fhead = new ListNode(0, head);
        ListNode* upper = fhead;
        ListNode* lower = head;;
        while (upper->next) {
            if (upper->next->val >= x && upper->next->next) {
                lower = upper->next;
                break;
            }
            else upper = upper->next;
        }
        if (upper->next == NULL)return fhead->next;
        while (lower->next) {
            if (lower->next->val < x) {
                ListNode* cur = lower->next;
                lower->next = cur->next;
                cur->next = upper->next;
                upper->next = cur;
                upper = upper->next;
            }
            else lower = lower->next;
        }
        return fhead->next;
    }
};