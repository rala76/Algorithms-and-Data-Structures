#include <iostream>

class DynamicArray {
private:
    int capacity = 0;
    int length = 0;
    int* arr;
public:
    // Constructor
    DynamicArray(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
    }

    // Return number of elements in the dynamic array
    int getSize() {
        return length;
    }
    
    // Return capacity of the dynamic array
    int getCapacity() {
        return capacity;
    }

    // Get value at i-th index
    int get(int i) {
        return arr[i];
    }

    // Insert val at i-th index
    void set(int i, int val) {
        arr[i] = val;
    }

    // Insert val in the last position of the array
    void pushback(int val) {
        if(length == capacity) {
            resize();
        }
        arr[length] = val;
        length++;
    }

    // Remove the last element in the array
    int popback() {
        length--;
        return arr[length];
    }

    // Resize the array by doubling the capacity
    void resize() {
        capacity = 2 * capacity;
        int* newArr = new int[capacity];
        
        // Copy elements to newArr
        for (int i = 0; i < length; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
    }
};

int main() {
    // Test Case #1
    // Input: ["Array", 1, "getSize", "getCapacity"]
    printf("Test Case #1\n");
    DynamicArray Array1(1);
    printf("getSize: %d\n", Array1.getSize());
    printf("getCapacity: %d\n\n", Array1.getCapacity());

    // Test Case #2
    printf("Test Case #2\n");
    // Input: ["Array", 1, "pushback", 1, "getCapacity", "pushback", 2, "getCapacity"]
    DynamicArray Array2(1);
    Array2.pushback(1);
    printf("getCapacity: %d\n", Array2.getCapacity());
    Array2.pushback(2);
    printf("getCapacity: %d\n\n", Array2.getCapacity());
    
    // Test Case #3
    printf("Test Case #3\n");
    // Input: ["Array", 1, "getSize", "getCapacity", "pushback", 1, "getSize", "getCapacity", 
    //         "pushback", 2, "getSize", "getCapacity", "get", 1, "set", 1, 3, "get", 1, 
    //         "popback", "getSize", "getCapacity"]
    DynamicArray Array3(1);
    printf("getSize: %d\n", Array3.getSize());
    printf("getCapacity: %d\n", Array3.getCapacity());
    Array3.pushback(1);
    printf("getSize: %d\n", Array3.getSize());
    printf("getCapacity: %d\n", Array3.getCapacity());
    Array3.pushback(2);
    printf("getSize: %d\n", Array3.getSize());
    printf("getCapacity: %d\n", Array3.getCapacity());
    Array3.get(1);
    Array3.set(1, 3);
    Array3.get(1);
    Array3.popback();
    printf("getSize: %d\n", Array3.getSize());
    printf("getCapacity: %d\n\n", Array3.getCapacity());

    return 0;
}