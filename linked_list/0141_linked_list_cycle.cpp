#include <set>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// My Solution Memory O(n)
class Solution {
public:
    static bool hasCycle(ListNode *head)
    {
        std::set<ListNode*> visited;

        while (head != nullptr)
        {
            if (visited.find(head) != visited.end()) return true;
            visited.insert(head);
            head = head->next;
        }
        return false;
    }
};

// With Floyd'd Cycle Memory O(1):
// class Solution {
// public:
//     static bool hasCycle(ListNode *head) {
//         if (!head || !head->next) return false;
//
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//
//         while (slow != fast) {
//             if (!fast || !fast->next) return false;
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return true;
//     }
// };
