class ListNode:
    def __init__(self, val = None, prev = None, next = None):
        self.val = val
        self.prev = prev
        self.next = next

class Queue:
    def __init__(self):
        self.head = None
        self.tail = None
    
    # Check if queue is empty
    def isEmpty(self):
        if self.head is None:
            return True
        
        return False
    
    # Insert val at end of queue
    def append(self, val):
        new_node = ListNode(val)
        
        if self.isEmpty():
            self.tail = new_node
            self.head = self.tail
        else:
            new_node.prev = self.tail
            self.tail.next = new_node
            self.tail = new_node
            
    
    # Insert val at beginning of queue
    def appendLeft(self, val):
        new_node = ListNode(val)

        if self.isEmpty():
            self.head = new_node
            self.tail = self.head
        else:
            new_node.next = self.head
            self.head.prev = new_node
            self.head = new_node
    
    # Remove and return val at end of queue, return -1 if empty
    def pop(self):
        if self.isEmpty():
            return -1
        
        value = self.tail.val
        
        if self.head == self.tail:
            self.tail = None
            self.head = None
        else:
            self.tail.prev.next = None
            self.tail = self.tail.prev

        return value
    
    # Remove and return val at beginning of queue, return -1 if empty
    def popLeft(self):
        if self.isEmpty():
            return -1
        
        value = self.head.next

        if self.head == self.tail:
            self.head = None
            self.tail = None
        else:
            self.head.next.prev = None
            self.head = self.head.next
        
        return value
    
    def print(self):
        values = []
        curr = self.head

        while curr:
            values.append(curr.val)
            curr = curr.next
        
        print(values)

def main():
    queue = Queue()
    
    print("append(2), append(3), appendLeft(1):")
    queue.append(2)
    queue.append(3)
    queue.appendLeft(1)
    queue.print()

    value1 = queue.pop()
    print("pop():")
    queue.print()

    value2 = queue.popLeft()
    print("popLeft():")
    queue.print()

if __name__ == "__main__":
    main()