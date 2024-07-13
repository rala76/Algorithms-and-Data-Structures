# Implementing a stack is trivial using a dynamic array, which was implemented earlier
class Stack:
    def __init__(self):
        self.stack = []

    # Insert on top of stack
    def push(self, val):
        self.stack.append(val)
    
    # Pop from top of stack
    def pop(self):
        return self.stack.pop()
    
    # Print stack
    def printStack(self):
        print(self.stack)

def main():
    s = Stack()

    s.push(1)
    s.push(2)
    s.push(3)
    s.push(4)
    s.printStack()

    popped = s.pop()
    s.printStack()

if __name__ == "__main__":
    main()