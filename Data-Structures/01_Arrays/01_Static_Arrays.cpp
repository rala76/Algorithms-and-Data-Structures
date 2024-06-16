#include <iostream>

// Insert val into arr at the next open position
// Length is the number of 'real' values in arr, and capacity is the size (aka memory allocated for the fixed size array)
void insertEnd(int arr[], int val, int& length, int capacity) {
    if (length < capacity) {
        arr[length] = val;
    }
    
    // Increase length by 1
    length += 1;
}

// Remove from the last position in the array if the array is not empty (i.e. length is non-zero)
void removeEnd(int arr[], int& length) {
    // Overwrite last element with some default value
    if (length > 0) {
        arr[length - 1] = 0;
    }
    
    // Decrease length by 1
    length -= 1;
}

// Insert val into index i after shifting elements to the right
// Assuming i is a valid index and arr is not full
void insertMiddle(int arr[], int i, int val, int& length) {
    // Shift starting from the end to i
    for (int index = length - 1; index >= i; index--) {
        arr[index + 1] = arr[index];
    }
    
    // Insert at i
    arr[i] = val;
    
    // Increase length by 1
    length += 1;
}

// Remove value at index i before shifting elements to the left
// Assuming i is a valid index
void removeMiddle(int arr[], int i, int& length) {
    for (int index = i + 1; index < length; index++) {
        arr[index - 1] = arr[index];
    }
    
    // Remove arr[i]
    arr[i] = 0;
    
    // Decrease length by 1
    length -= 1;
}

// Prints array
void printArr(int arr[], int capacity) {
    for (int i = 0; i < capacity; i++) {
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}

int main() {
    // Initialize array with values
    int arr1[5] = {1, 2, 3, 4, 5};

    // Initialize an array partially while a '0' is stored in the rest of the indices
    int arr2[5] = {1, 2};
    
    // Initialize array with values and without size
    int arr3[] = {1, 2, 3, 4, 5};

    // Initialize array with zeros
    int arr4[5] = {0};

    // Initialize array after declaration (using loops)
    int arr5[5];
    for (int i = 0; i < 5; i++) {
        arr5[i] = i + 1;
    }

    // Array operations
    const int capacity = 5;
    int arr6[capacity] = {1, 2, 3};
    int length = 3;

    std::cout << "Insert '5' at the next open position: " << std::endl;
    insertEnd(arr6, 5, length, capacity);
    printArr(arr6, capacity);
    std::cout << std::endl;

    std::cout << "Insert '4' at index 3: " << std::endl;
    insertMiddle(arr6, 3, 4, length);
    printArr(arr6, capacity);
    std::cout << std::endl;

    std::cout << "Remove the last position in the array: " << std::endl;
    removeEnd(arr6, length);
    printArr(arr6, capacity);
    std::cout << std::endl;

    std::cout << "Remove '4' at index 3: " << std::endl;
    removeMiddle(arr6, 3, length);
    printArr(arr6, capacity);
    std::cout << std::endl;
    
    return 0;
}