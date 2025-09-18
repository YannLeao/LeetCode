#include <iostream>
#include <vector>

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
    static ListNode* removeElements(ListNode* head, int val)
    {
        auto dummy = new ListNode(-1, head);

        ListNode* previous = dummy;
        ListNode* current = head;

        while (current)
        {
            if (current->val == val)
            {
                previous->next = current->next;
                current = current->next;
            }
            else
            {
                current = current->next;
                previous = previous->next;
            }
        }
        return dummy->next;
    }
};

ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    auto head = new ListNode(values[0]);
    ListNode* current = head;
    for (size_t i = 1; i < values.size(); ++i) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    return head;
}

void printList(const ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* l1 = createList({7,7,7,7});

    ListNode* result = Solution::removeElements(l1, 7);
    printList(result);

    return 0;
}