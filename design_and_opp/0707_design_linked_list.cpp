struct Node
{
    int value;
    Node *next;
    Node() : value(0), next(nullptr) {}
    explicit Node(int x) : value(x), next(nullptr) {}
};

class MyLinkedList {
    Node *head;
    int length;
public:
    MyLinkedList() : head(nullptr), length(0) {}

    ~MyLinkedList() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
    
    int get(int index) {
        if (index < 0 || index >= length) return -1;

        auto n = head;
        for (int i = 0; i < index; ++i) n = n->next;
        return n->value;
    }

    void addAtHead(int val) {
        Node* newHead = new Node(val);
        newHead->next = head;
        head = newHead;
        length++;
    }
    
    void addAtTail(int val) {
        Node* newTail = new Node(val);
        if (!head)
        {
            head = newTail;
        }
        else
        {
            auto n = head;
            while (n->next != nullptr) n = n->next;
            n->next = newTail;
        }
        length++;
    }
    
    void addAtIndex(int index, int val) {
        if (index < 0 || index > length) return;
        if (index == 0) {addAtHead(val); return;}
        if (index == length) {addAtTail(val); return;}

        auto previous = head;
        for (int i = 0; i < index - 1; ++i) previous = previous->next;

        Node* newNode = new Node(val);
        newNode->next = previous->next;
        previous->next = newNode;
        length++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;

        if (index == 0)
        {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        else
        {
            auto previous = head;
            for (int i = 0; i < index - 1; ++i) previous = previous->next;

            Node* toDelete = previous->next;
            previous->next = toDelete->next;
            delete toDelete;
        }
        length--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */