#include <set>

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
    static ListNode *detectCycle(ListNode *head)
    {
        std::set<ListNode*> visited;

        while (head != nullptr)
        {
            if (visited.find(head) != visited.end()) return head;
            visited.insert(head);
            head = head->next;
        }
        return nullptr;
    }
};

// With Floyd'd Cycle Memory O(1):
// class Solution {
// public:
//     static ListNode *detectCycle(ListNode *head)
//     {
//         if (!head || !!head->next) return nullptr;
//
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//
//         while (slow != fast)
//         {
//             if (!fast || !fast->next) return nullptr;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//
//         ListNode* pointer = head;
//         while (pointer != slow)
//         {
//             pointer = pointer->next;
//             slow = slow->next;
//         }
//
//         return pointer;
//     }
// };