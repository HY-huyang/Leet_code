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
。
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
