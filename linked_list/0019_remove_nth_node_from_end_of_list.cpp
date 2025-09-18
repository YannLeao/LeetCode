struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        int steps = 0;

        while (ptr1->next)
        {
            ptr1 = ptr1->next;
            if (steps == n) ptr2 = ptr2->next;
            else steps++;
        }
        if (n - steps > 0) head = head->next;
        else ptr2->next = ptr2->next->next;

        return head;
    }
};