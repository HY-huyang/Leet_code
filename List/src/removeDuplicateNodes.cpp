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