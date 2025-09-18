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
    static bool isPalindrome(ListNode* head)
    {
        // Linked-list middle
        auto fast = head;
        auto slow = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse
        auto current = slow;
        ListNode* previous = nullptr;
        while (current)
        {
            ListNode* temp = current->next;
            current->next = previous;
            previous = current;
            current = temp;
        }

        // Compare
        auto ptr1 = head;
        auto ptr2 = previous;
        while (ptr2)
        {
            if (ptr1->val != ptr2->val) return false;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return true;
    }
};