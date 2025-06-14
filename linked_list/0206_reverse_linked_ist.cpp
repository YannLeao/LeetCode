struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;

        ListNode* next = head->next;
        ListNode* previous = nullptr;

        while (next)
        {
            ListNode* temp = next->next;
            next->next = head;
            head->next = previous;
            previous = head;
            head = next;
            next = temp;
        }
        return head;
    }
};