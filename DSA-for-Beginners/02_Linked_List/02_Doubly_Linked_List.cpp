#include <iostream>

class ListNode {
public:
    int val;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    // Constructors
    ListNode() {}
    ListNode(int val) {
        this->val = val;
    }
};

class LinkedList {
private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
public:
    // Constructor
    LinkedList() {}

    // Check if doubly linked list is empty
    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }

        return false;
    }

    // Insert node at the head of the doubly linked list
    void insertFront(int val) {
        ListNode* new_node = new ListNode(val);

        if (isEmpty()) {
            head = new_node;
            tail = head;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    // Insert node at the tail of the doubly linked list
    void insertEnd(int val) {
        ListNode* new_node = new ListNode(val);

        if (isEmpty()) {
            tail = new_node;
            head = tail;
        } else {
            new_node->prev = tail;
            tail->next = new_node;
            tail = new_node;
        }
    }

    // Remove node at the head of the doubly linked list
    void removeFront() {
        if (!isEmpty()) {
            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                head->next->prev = nullptr;
                head = head->next;
            }
        }
    }

    // Remove node at the tail of the doubly linked list
    void removeEnd() {
        if (!isEmpty()) {
            if (head == tail) {
                tail = nullptr;
                head = nullptr;
            } else {
                tail->prev->next = nullptr;
                tail = tail->prev;
            }
        }
    }

    // Print the doubly linked list
    void print() {
        ListNode* curr = head;
        while (curr != nullptr) {
            printf("<-[%d]->", curr->val);
            curr = curr->next;
        }
        printf("\n");
    }
};

int main() {
    LinkedList dll1;

    printf("insertFront(2), insertEnd(3), insertFront(1), print(): \n");
    dll1.insertFront(2);
    dll1.insertEnd(3);
    dll1.insertFront(1);
    dll1.print();

    printf("removeFront(), removeEnd(), print(): \n");
    dll1.removeFront();
    dll1.removeEnd();
    dll1.print();

    return 0;
}