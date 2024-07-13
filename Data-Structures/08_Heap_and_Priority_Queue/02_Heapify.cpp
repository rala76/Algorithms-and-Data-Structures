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

    // Implemeneted previously
    void push(int val) {}
    int pop() {}
    int top() {}

    void heapify(vector<int>& arr) {
        // 0-th position is moved to the end
        arr.push_back(arr[0]);

        heap = arr;
        int curr = (heap.size() - 1) / 2;
        while (curr > 0) {
            int i = curr;

            // Index to children
            int left_child = 2 * i;
            int right_child;

            // Percolate down
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

            // Next node
            curr--;
        }
    }
};

int main() {
    vector<int> arr = {60, 50, 80, 40, 30, 10, 70, 20, 90};

    Heap heap;
    heap.heapify(arr);

    return 0;
}