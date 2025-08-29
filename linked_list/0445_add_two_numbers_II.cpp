#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = Solution::reverseList(l1);
        l2 = Solution::reverseList(l2);

        ListNode* result = Solution::myAddTwoNumbers(l1, l2);
        return Solution::reverseList(result);
    }

    static ListNode* reverseList(ListNode* head) {
        if (!head->next) return head;

        ListNode* previous = nullptr;

        while (head)
        {
            ListNode* next = head->next;
            head->next = previous;
            previous = head;
            head = next;
        }
        return previous;
    }
    static ListNode* myAddTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp = new ListNode(0);
        ListNode* result = temp;
        int carry_in = 0;
        
        while (l1 != nullptr || l2 != nullptr)
        {
            int n1 = (l1 != nullptr) ? l1->val : 0;
            int n2 = (l2 != nullptr) ? l2->val : 0;
            int sum = n1 + n2 + carry_in;

            temp->next = new ListNode(sum % 10);
            carry_in = sum / 10;

            temp = temp->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }
        if (carry_in != 0) temp->next = new ListNode(carry_in);
        return result->next;
    }
};

ListNode* createList(const std::vector<int>& values) {
    if (values.empty()) return nullptr;
    ListNode* head = new ListNode(values[0]);
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
    ListNode* l1 = createList({7, 2, 4, 3});
    ListNode* l2 = createList({5, 6, 4});

    ListNode* result = Solution::addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}