#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
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

class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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

int main() {
    ListNode* l1 = createList({6,7,8,0,8,5,8,9,7});
    ListNode* l2 = createList({0});

    ListNode* result = Solution::addTwoNumbers(l1, l2);
    printList(result);

    return 0;
}