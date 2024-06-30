#include <iostream>
#include <vector>

using std::vector;

void selectionSort(vector<int>& arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        
        // Find the minimum in the unsorted part of array
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }

        // Move the minimum value to the fron of the unsorted part of array
        if (min != i) {
            std::swap(arr[i], arr[min]);
        }
    }
}

int main() {
    vector<int> arr = {2, 8, 5, 3, 9, 4, 1};
    int n = arr.size();

    selectionSort(arr, n);
    
    for (int i = 0; i < n; i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    return 0;
}