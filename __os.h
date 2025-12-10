// cout<< list
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

// cout<< vector
template<typename T>
ostream& operator << (ostream& os, const vector<T>& num) {
    os << '[';
    int n = num.size();
    for (int i = 0; i < n; i++) {
        os << num[i];
        if (i == n - 1)break;
        os << ',';
    }
    os << ']';
    return os;
}
