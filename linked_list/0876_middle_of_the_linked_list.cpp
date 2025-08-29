#include <iostream>
#include <ostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* temp = head;

        while (temp)
        {
            temp = temp->next;
            size++;
        }
        int iterations = size/2;

        for (int i = 0; i < iterations; ++i)
        {
            head = head->next;
        }

        return head;
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
    ListNode* l1 = createList({1, 2, 3, 4, 5,});

    ListNode* result = Solution::middleNode(l1);
    printList(result);

    return 0;
}