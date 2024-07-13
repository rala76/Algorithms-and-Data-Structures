#include <iostream>
#include <vector>

using std::vector;

// Min Heap
class Heap {
public:
    vector<int> heap;

    Heap() {
        heap.push_back(0);
    }

    void push(int val) {
        heap.push_back(val);
        int i = heap.size() - 1;
        
        // Percolate up
        while (i > 1 && heap[i] < heap[i / 2]) {
            int temp = heap[i];
            heap[i] = heap[i / 2];
            heap[i / 2] = temp;
            i = i / 2;
        }
    }

    int pop() {
        if (heap.size() == 1) {
            // Normally we would throw an exception if heap is empty.
            return -1;
        }
        if (heap.size() == 2) {
            int res = heap[heap.size() - 1];
            heap.pop_back();
            return res;
        }

        int res = heap[1];
        
        // Move last value to root
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        int i = 1;
        
        // Index to children
        int left_child = 2 * i;
        int right_child;

        // Percolate down - while loop runs while there is a left_child
        while (left_child < heap.size()) {
            left_child = 2 * i;
            right_child = 2 * i + 1;

            if (right_child < heap.size() && heap[right_child] < heap[left_child] && heap[i] > heap[right_child]) {
                // Swap right child
                int temp = heap[i];
                heap[i] = heap[right_child];
                heap[right_child] = temp;
                i = right_child;
            } else if (heap[i] > heap[left_child]) {
                // Swap left child
                int temp = heap[i];
                heap[i] = heap[left_child];
                heap[left_child] = temp;
                i = left_child;
            } else {
                break;
            }
        }

        return res;
    }

    int top() {
        if (heap.size() > 1) {
            return heap[1];
        }

        // Normally we would throw an exception if heap is empty.
        return -1;
    }
};

int main() {
    Heap heap;

    // Create the heap
    heap.push(14);
    heap.push(19);
    heap.push(16);
    heap.push(21);
    heap.push(26);
    heap.push(19);
    heap.push(68);
    heap.push(65);
    heap.push(30);

    // Insert 17
    heap.push(17);

    // Remove
    heap.pop();

    // Top, in this case the minimum value
    int min_value = heap.top();
    printf("%d\n", min_value);

    return 0;
}