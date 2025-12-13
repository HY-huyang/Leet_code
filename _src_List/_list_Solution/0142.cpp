// unordered_set
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        unordered_set<ListNode*>set;
        ListNode* curr = head;
        while (head) {
            if (set.count(head)) return head;
            set.insert(head);
            head = head->next;
        }
        return NULL;

    }
};

// 快慢指针
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        if (!head || !head->next) return NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                slow = head;
                while (slow != fast) {
                    fast = fast->next;
                    slow = slow->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};
