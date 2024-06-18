#include <iostream>
#include <vector>

// Implementing a stack is trivial using a dynamic array, which was implemented earlier
class Stack {
private:
    std::vector<int> stack;
public:
    // Constructor
    Stack() {};

    // Insert on top of stack
    void push(int val) {
        stack.push_back(val);
    }

    // Pop from top of stack
    int pop() {
        int res = stack[stack.size() - 1];
        stack.pop_back();
        return res;
    }

    // Retrieve the last element
    int peek() {
        int top = stack.back();
        return top;
    }

    // Print stack
    void printStack() {
        for (int i = 0; i < stack.size(); i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.printStack();

    s.pop();
    int top = s.peek();
    printf("Top: %d\n", top);

    return 0;
}