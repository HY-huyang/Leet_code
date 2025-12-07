ostream& operator<<(ostream& os, const ListNode* node) {
    const ListNode* current = node;
    os << "["; 
    while (current != NULL) {
        os << current->val; 
        if (current->next != NULL) {
            os << ", "; 
        }
        current = current->next;
    }
    os << "]"; 
    return os;
}