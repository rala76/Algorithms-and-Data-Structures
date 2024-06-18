#include <iostream>

class ListNode{
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

class Queue {
private:
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
public:
    Queue() {}

    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }

        return false;
    }

    void append(int val) {
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

    void appendLeft(int val) {
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

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        int value = tail->val;

        if (head == tail) {
            tail = nullptr;
            head = nullptr;
        } else {
            tail->prev->next = nullptr;
            tail = tail->prev;
        }

        return value;
    }

    int popLeft() {
        if (isEmpty()) {
            return -1;
        }
    
        int value = head->val;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head->next->prev = nullptr;
            head = head->next;
        }

        return value;
    }

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
    Queue queue;

    printf("append(2), append(3), appendLeft(1): \n");
    queue.append(2);
    queue.append(3);
    queue.appendLeft(1);
    queue.print();

    int value1 = queue.pop();
    printf("pop(): %d\n", value1);
    queue.print();

    int value2 = queue.popLeft();
    printf("popLeft(): %d\n", value2);
    queue.print();

    return 0;
}