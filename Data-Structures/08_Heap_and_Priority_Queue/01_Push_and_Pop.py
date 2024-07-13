# Min Heap
class Heap:
    def __init__(self):
        self.heap = [0]
    
    def push(self, val):
        self.heap.append(val)
        i = len(self.heap) - 1

        # Percolate up
        while i > 1 and self.heap[i] < self.heap[i // 2]:
            tmp = self.heap[i]
            self.heap[i] = self.heap[i // 2]
            self.heap[i // 2] = tmp
            i = i // 2
    
    def pop(self):
        # Empty heap, dummy variable for index 0
        if len(self.heap) == 1:
            return None
        # Single element in heap
        if len(self.heap) == 2:
            self.heap.pop()
        
        res = self.heap[1]

        # Move last value to root
        self.heap[1] = self.heap.pop()
        i = 1

        # Percolate down - while loop runs while there is a left child
        while 2 * i < len(self.heap):
            # Index of children
            leftChild = 2 * i
            rightChild = 2 * i + 1

            # If rightChild exist and rightChild < leftChild and parent > rightChild
            if rightChild < len(self.heap) and self.heap[rightChild] < self.heap[leftChild] and self.heap[i] > self.heap[rightChild]:
                # Swap right child
                tmp = self.heap[i]
                self.heap[i] = self.heap[rightChild]
                self.heap[rightChild] = tmp
                i = rightChild
            # If not righChild check leftChild
            elif self.heap[i] > self.heap[leftChild]:
                # Swap left child
                tmp = self.heap[i]
                self.heap[i] = self.heap[leftChild]
                self.heap[leftChild] = tmp
                i = leftChild
            # Proper position in heap
            else:
                break
        
        return res
    
    def top(self):
        if len(self.heap) > 1:
            return self.heap[1]
        
        return None

def main():
    heap = Heap()

    # Create the min heap
    heap.push(14)
    heap.push(19)
    heap.push(16)
    heap.push(21)
    heap.push(26)
    heap.push(19)
    heap.push(68)
    heap.push(65)
    heap.push(30)

    # Insert 17
    heap.push(17)

    # Remove priority value (min heap priority is min value, aka root node)
    heap.pop()

    # Top, in this case the min value
    minVal = heap.top()
    print(minVal)

if __name__ == "__main__":
    main()