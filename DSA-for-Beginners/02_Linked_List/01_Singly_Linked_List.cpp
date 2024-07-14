#include <iostream>
#include <vector>

class ListNode {
public:
    int val;
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

    // Check if singly linked list is empty
    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }

        return false;
    }

    // Return the value of the node at index
    int get(int index) {
        ListNode* curr = head;
        int curr_index = 0;

        while (curr != nullptr) {
            if (curr_index == index) {
                return curr->val;
            }
            curr = curr->next;
            curr_index++;
        }

        return -1;
    }

    // Insert node at the head of the singly linked list
    void insertHead(int val) {
        ListNode* new_node = new ListNode(val);

        if (isEmpty()) {
            head = new_node;
            tail = head;
        } else {
            new_node->next = head;
            head = new_node;
        }
    }

    // Insert node at the tail of the singly linked list
    void insertTail(int val) {
        ListNode* new_node = new ListNode(val);
        
        if (isEmpty()) {
            tail = new_node;
            head = tail;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    bool remove(int index) {
        if (isEmpty()) {
            return false;
        }

        ListNode* prev = nullptr;
        ListNode* curr = head;
        int curr_index = 0;

        while (curr != nullptr) {
            if (curr_index == index) {
                if (curr == head) {
                    head = curr->next;

                    if (head == nullptr) {
                        tail = nullptr;
                    }
                } else {
                    prev->next = curr->next;

                    if (curr == tail) {
                        tail = prev;
                    }
                }

                delete curr;
                return true;
            }
            
            prev = curr;
            curr = curr->next;
            curr_index++;
        }

        return false;
    }

    std::vector<int> getValues() {
        std::vector<int> values;
        ListNode* curr = head;

        while (curr != nullptr) {
            values.push_back(curr->val);
            curr = curr->next;
        }

        return values;
    }
};

void printValues(std::vector<int> v) {
    for (int i = 0; i < v.size(); i++) {
        printf("[%d] -> ", v[i]);
    }
    printf("nullptr\n");
}

int main() {
    // Test Case #1
    printf("Test Case 1:\n");
    // Input: ["insertHead", 1, "insertTail", 2, "insertHead", 0, "remove", 1, "getValues"]
    LinkedList sll1;
    sll1.insertHead(1);
    sll1.insertTail(2);
    sll1.insertHead(0);
    bool result = sll1.remove(1);
    printf("%s\n", result ? "true" : "false");
    std::vector<int> values = sll1.getValues();
    printValues(values);

    printf("\n");
    
    // Test Case #2
    printf("Test Case 2:\n");
    // Input: ["insertHead", 1, "insertHead", 2, "get", 5]
    LinkedList sll2;
    sll2.insertHead(1);
    sll2.insertHead(2);
    int value = sll2.get(5);
    printf("%d", value);

    return 0;
}