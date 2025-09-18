class Node {
public:
    int val;
    Node* next;
    Node* random;

    explicit Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    static Node* copyRandomList(Node* head)
    {
        auto current = head;
        while (current)
        {
            auto next = current->next;
            current->next = new Node(current->val);
            current->next->next = next;
            current = current->next->next;
        }

        current = head;
        while (current)
        {
            if (current->random) current->next->random = current->random->next;
            current = current->next->next;
        }

        current = head;
        auto newHead = head->next;
        auto newCurrent = head->next;
        while (current)
        {
            current->next = newCurrent->next;
            current = current->next;

            if (current)
            {
                newCurrent->next = current->next;
                newCurrent = newCurrent->next;
            }
        }
        return newHead;
    }
};