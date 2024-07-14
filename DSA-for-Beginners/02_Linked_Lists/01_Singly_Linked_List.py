class ListNode:
    def __init__(self, val = None, next = None):
        self.val = val
        self.next = next

# Implementation for Singly Linked List
class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
    
    # Check if singly linked list is empty
    def isEmpty(self):
        if self.head is None:
            return True
        
        return False
    
    # Return the value of the node at index
    def get(self, index):
        curr = self.head
        curr_index = 0

        while curr != None:
            if curr_index == index:
                return curr.val
            
            curr = curr.next
            curr_index += 1
        
        return -1
    
    # Insert node at the head of the singly linked list
    def insertHead(self, val):
        new_node = ListNode(val)

        if self.isEmpty():
            self.head = new_node
            self.tail = self.head
        else:
            new_node.next = self.head
            self.head = new_node
    
    # Insert node at the tail of the singly linked list
    def insertTail(self, val):
        new_node = ListNode(val)

        if (self.isEmpty()):
            self.tail = new_node
            self.head = self.tail
        else:
            self.tail.next = new_node
            self.tail = new_node
    
    def remove(self, index):
        if self.isEmpty():
            return False
        
        prev = None
        curr = self.head
        curr_index = 0

        while curr is not None:
            if curr_index == index:
                if curr == self.head:
                    self.head = curr.next

                    if self.head is None:
                        self = None
                else:
                    prev.next = curr.next

                    if curr == self.tail:
                        self.tail = prev
                
                return True
            
            prev = curr
            curr = curr.next
            curr_index += 1
        
        return False
    
    def getValues(self):
        values = []
        curr = self.head

        while curr:
            values.append(curr.val)
            curr = curr.next
        
        return values

def main():
    # Test Case #1
    # Input: ["insertHead", 1, "insertTail", 2, "insertHead", 0, "remove", 1, "getValues"]
    print("Test Case 1:")
    SLL1 = LinkedList()
    SLL1.insertHead(1)
    SLL1.insertTail(2)
    SLL1.insertHead(0)
    result = SLL1.remove(0)
    if result:
        print("Successfully removed")
    else:
        print("Unsuccessfully removed")
    values = SLL1.getValues()
    print(values)

    # Test Case #2
    # Input: ["insertHead", 1, "insertHead", 2, "get", 5]
    print("Test Case 2:")
    SLL2 = LinkedList()
    SLL2.insertHead(1)
    SLL2.insertHead(2)
    value = SLL2.get(5)
    print(value)

if __name__ == "__main__":
    main()