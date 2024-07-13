# Min Heap
class Heap:
    def __init__(self):
        self.heap = [0]
    
    # ... push, pop implemented previously
    # def push(self, val):
    # def pop(self):
    
    def heapify(self, arr):
        # Copy arr and 0th position is moved to the end
        self.heap = arr
        self.heap.append(self.heap[0])
        
        curr = (len(self.heap) - 1) // 2
        while curr > 0:
            i = curr

            # Percolate down
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
                # If not rightChild, check leftChild
                elif self.heap[i] > self.heap[leftChild]:
                    # Swap left child
                    tmp = self.heap[i]
                    self.heap[i] = self.heap[leftChild]
                    self.heap[leftChild] = tmp
                    i = leftChild
                # Proper position in heap
                else:
                    break
            
            # Next node
            curr -= 1
    
    def top(self):
        if len(self.heap) > 1:
            return self.heap[1]
        
        return None

def main():
    arr = [60, 50, 80, 40, 30, 10, 70, 20, 90]

    heap = Heap()
    heap.heapify(arr)
    minVal = heap.top()
    print(minVal)

if __name__ == "__main__":
    main()