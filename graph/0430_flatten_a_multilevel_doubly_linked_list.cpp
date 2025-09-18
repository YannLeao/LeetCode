class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
public:
    static Node* flatten(Node* head)
    {
        flattenDFS(head);
        return head;
    }

private:
    static Node* flattenDFS(Node* node)
    {
        auto current = node;
        auto last = node;
        while (current)
        {
            auto next = current->next;
            if (current->child)
            {
                auto childHead = current->child;
                auto childTail = flattenDFS(childHead);

                current->next = childHead;
                childHead->prev = current;

                if (next)
                {
                    childTail->next = next;
                    next->prev = childTail;
                }

                current->child = nullptr;
                last = childTail;
            }
            else last = current;

            current = next;
        }

        return last;
    }
};