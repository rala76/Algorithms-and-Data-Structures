class ListNode:
    def __init__(self, val = None, prev = None, next = None):
        self.val = val
        self.prev = prev
        self.next = next

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    # Check if doubly linked list is empty
    def isEmpty(self):
        if self.head is None:
            return True
        
        return False
    
    # Insert node at the head of the doubly linked list
    def insertFront(self, val):
        new_node = ListNode(val)

        if self.isEmpty():
            self.head = new_node
            self.tail = self.head
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
    
    # Insert node at the tail of the doubly linked list
    def insertEnd(self, val):
        new_node = ListNode(val)

        if self.isEmpty():
            self.tail = new_node
            self.head = self.tail
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
    
    # Remove node at the head of the doubly linked list
    def removeFront(self):
        if self.isEmpty():
            return
        
        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head.next.prev = None
            self.head = self.head.next
    
    # Remove node at the tail of the doubly linked list
    def removeEnd(self):
        if self.isEmpty():
            return
        
        if self.head == self.tail:
            self.tail = None
            self.head = None
        else:
            self.tail.prev.next = None
            self.tail = self.tail.prev
    
    def getValues(self):
        values = []
        curr = self.head

        while curr:
            values.append(curr.val)
            curr = curr.next
        
        return values

def main():
    DLL1 = LinkedList()

    print("insertFront(2), insertEnd(3), insertFront(1), print():")
    DLL1.insertFront(2)
    DLL1.insertEnd(3)
    DLL1.insertFront(1)
    print(DLL1.getValues())

    print("removeFront(), removeEnd(), print():")
    DLL1.removeFront()
    DLL1.removeEnd()
    print(DLL1.getValues())

if __name__ == "__main__":
    main()