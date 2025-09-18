struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    static ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;

        int size = 1;
        auto start = head;
        while (start->next) { start = start->next; ++size; }
        k %= size;

        int tailIndex = size - k - 1;
        auto tail = head;
        while (tailIndex > 0) { tail = tail->next; --tailIndex; }

        auto newHead = tail->next;
        tail->next = nullptr;
        start->next = head;

        return newHead;
    }
};