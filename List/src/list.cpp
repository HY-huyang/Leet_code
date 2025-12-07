class Solution {
public:
    ListNode* removeDuplicateNodes(ListNode* head) {
        unordered_map<int, int>map;
        int i = 0;
        map[head->val] = i++;
        ListNode* pre = head;
        ListNode* ls = pre->next;
        while (ls) {
            int tmp = ls->val;
            auto it = map.find(tmp);
            if (ls->next != NULL)
            {
                if (it != map.end()) {
                    pre->next = ls->next;
                    ls->next = NULL;
                    delete(ls);
                }
                else {
                    map[tmp] = i++;
                    pre = ls;
                }
                ls = pre->next;
            }
            else {
                if (it != map.end())pre->next = NULL;
                break;
            }
        }

        return head;
    }
};

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