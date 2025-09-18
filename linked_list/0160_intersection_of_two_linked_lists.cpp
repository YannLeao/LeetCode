struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution Memory O(1) and Runtime O(n)
class Solution {
public:
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        int sizeA = 1;
        int sizeB = 1;

        auto nodeA = headA;
        auto nodeB = headB;

        while (nodeA->next) {nodeA = nodeA->next; sizeA++;}
        while (nodeB->next) {nodeB = nodeB->next; sizeB++;}

        while (sizeA != sizeB)
        {
            if (sizeA > sizeB) { headA = headA->next; sizeA--; }
            else { headB = headB->next; sizeB--; }
        }

        while (headA && headB)
        {
            if (headA == headB) return headA;
            else
            {
                headA = headA->next;
                headB = headB->next;
            }
        }

        return nullptr;
    }
};